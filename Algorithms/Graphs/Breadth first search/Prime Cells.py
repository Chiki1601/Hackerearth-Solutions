import sys
import heapq


def solve():
    input = sys.stdin.buffer.readline

    R, C = map(int, input().split())

    A = []
    mx = 0

    for _ in range(R):
        row = list(map(int, input().split()))
        A.append(row)
        mx = max(mx, max(row))

    # ---------------------------------------------------------
    # Smallest Prime Factor sieve
    # ---------------------------------------------------------
    spf = list(range(mx + 1))

    if mx >= 1:
        spf[1] = 1

    for i in range(2, int(mx ** 0.5) + 1):
        if spf[i] == i:
            start = i * i
            for j in range(start, mx + 1, i):
                if spf[j] == j:
                    spf[j] = i

    # ---------------------------------------------------------
    # omega[x] = number of prime factors
    # hpf[x]   = highest prime factor
    #
    # For 1, according to the statement:
    # count of prime factors = 1
    # highest prime factor = 1
    # ---------------------------------------------------------
    omega = [0] * (mx + 1)
    hpf = [0] * (mx + 1)

    if mx >= 1:
        omega[1] = 1
        hpf[1] = 1

    for x in range(2, mx + 1):
        p = spf[x]
        y = x // p

        omega[x] = omega[y] + 1
        hpf[x] = max(p, hpf[y])

    # ---------------------------------------------------------
    # Store information for every cell
    # ---------------------------------------------------------
    N = R * C

    typ = [0] * N
    high = [0] * N
    value = [0] * N

    for r in range(R):
        base = r * C
        for c in range(C):
            idx = base + c
            x = A[r][c]

            typ[idx] = omega[x]
            high[idx] = hpf[x]
            value[idx] = x

    # ---------------------------------------------------------
    # Find connected components having equal omega.
    # ---------------------------------------------------------
    visited = bytearray(N)

    best_cells = []
    best_score = -1

    for start in range(N):
        if visited[start]:
            continue

        t = typ[start]

        stack = [start]
        visited[start] = 1

        cells = []
        total = 0

        while stack:
            u = stack.pop()
            cells.append(u)
            total += value[u]

            r = u // C
            c = u - r * C

            # up
            if r > 0:
                v = u - C
                if not visited[v] and typ[v] == t:
                    visited[v] = 1
                    stack.append(v)

            # down
            if r + 1 < R:
                v = u + C
                if not visited[v] and typ[v] == t:
                    visited[v] = 1
                    stack.append(v)

            # left
            if c > 0:
                v = u - 1
                if not visited[v] and typ[v] == t:
                    visited[v] = 1
                    stack.append(v)

            # right
            if c + 1 < C:
                v = u + 1
                if not visited[v] and typ[v] == t:
                    visited[v] = 1
                    stack.append(v)

        score = total * len(cells)

        if score > best_score:
            best_score = score
            best_cells = cells

    # ---------------------------------------------------------
    # The initial best component.
    # ---------------------------------------------------------
    target_type = typ[best_cells[0]]

    selected = bytearray(N)

    for u in best_cells:
        selected[u] = 1

    # ---------------------------------------------------------
    # Find a reasonable target number for a cell.
    #
    # We need:
    #   omega[new] = target_type
    #
    # and want the highest prime factor to be close to
    # the original highest prime factor.
    #
    # For a number with t prime factors and highest prime p,
    # p^t is a valid choice.
    # ---------------------------------------------------------

    # Generate primes up to mx.
    is_prime = bytearray(b'\x01') * (mx + 1)

    if mx >= 0:
        is_prime[0] = 0
    if mx >= 1:
        is_prime[1] = 0

    for i in range(2, int(mx ** 0.5) + 1):
        if is_prime[i]:
            is_prime[i * i:mx + 1:i] = b'\x00' * (
                ((mx - i * i) // i) + 1
            )

    primes = [i for i in range(2, mx + 1) if is_prime[i]]

    # Valid highest prime factors for this omega.
    valid_powers = []

    if target_type == 1:
        for p in primes:
            if p <= mx:
                valid_powers.append((p, p))
    else:
        for p in primes:
            x = 1

            for _ in range(target_type):
                x *= p
                if x > mx:
                    break

            if x <= mx:
                valid_powers.append((p, x))

    # If there is no possible target, just output the original matrix.
    if not valid_powers:
        out = [f"{R} {C}"]

        for row in A:
            out.append(" ".join(map(str, row)))

        sys.stdout.write("\n".join(out))
        return

    # ---------------------------------------------------------
    # Binary search helper.
    # Find valid p closest to a given highest prime factor.
    # ---------------------------------------------------------
    p_values = [x[0] for x in valid_powers]
    p_numbers = [x[1] for x in valid_powers]

    import bisect

    def best_replacement(old_hpf):
        pos = bisect.bisect_left(p_values, old_hpf)

        candidates = []

        if pos < len(p_values):
            candidates.append(pos)

        if pos > 0:
            candidates.append(pos - 1)

        best = None

        for k in candidates:
            p = p_values[k]
            new_value = p_numbers[k]
            cost = abs(old_hpf - p)

            if best is None or cost < best[0]:
                best = (cost, new_value)

        return best

    # ---------------------------------------------------------
    # Expand the component.
    #
    # We use a priority queue. Cells with low modification cost
    # are preferred.
    # ---------------------------------------------------------
    in_heap = bytearray(N)
    heap = []

    for u in best_cells:
        r = u // C
        c = u - r * C

        neighbours = []

        if r > 0:
            neighbours.append(u - C)
        if r + 1 < R:
            neighbours.append(u + C)
        if c > 0:
            neighbours.append(u - 1)
        if c + 1 < C:
            neighbours.append(u + 1)

        for v in neighbours:
            if selected[v] or in_heap[v]:
                continue

            if typ[v] == target_type:
                # Already compatible. No modification needed.
                selected[v] = 1
                heapq.heappush(heap, (0, -value[v], v))
                in_heap[v] = 1
            else:
                cost, new_value = best_replacement(high[v])

                heapq.heappush(
                    heap,
                    (cost, -new_value, v)
                )
                in_heap[v] = 1

    # Keep track of component sum and size.
    current_sum = sum(value[u] for u in best_cells)
    current_size = len(best_cells)
    total_cost = 0

    modified = A[:]
    
    # ---------------------------------------------------------
    # Greedily add cells if they improve the score.
    # ---------------------------------------------------------
    while heap:
        cost, neg_new_value, u = heapq.heappop(heap)

        if selected[u]:
            continue

        new_value = -neg_new_value

        # For cells already having target type, no cost.
        if typ[u] == target_type:
            actual_cost = 0
            actual_value = value[u]
        else:
            actual_cost, actual_value = best_replacement(high[u])

        new_sum = current_sum + actual_value
        new_size = current_size + 1
        new_cost = total_cost + actual_cost

        old_score = (
            current_sum * current_size
            / (1 + total_cost)
        )

        new_score = (
            new_sum * new_size
            / (1 + new_cost)
        )

        # Only take the cell when it improves the score.
        if new_score >= old_score:
            selected[u] = 1
            current_sum = new_sum
            current_size = new_size
            total_cost = new_cost

            if typ[u] != target_type:
                r = u // C
                c = u - r * C
                modified[r][c] = actual_value

            # Add new neighbours.
            r = u // C
            c = u - r * C

            neighbours = []

            if r > 0:
                neighbours.append(u - C)
            if r + 1 < R:
                neighbours.append(u + C)
            if c > 0:
                neighbours.append(u - 1)
            if c + 1 < C:
                neighbours.append(u + 1)

            for v in neighbours:
                if selected[v] or in_heap[v]:
                    continue

                if typ[v] == target_type:
                    heapq.heappush(
                        heap,
                        (0, -value[v], v)
                    )
                else:
                    cost2, new_value2 = best_replacement(high[v])

                    heapq.heappush(
                        heap,
                        (cost2, -new_value2, v)
                    )

                in_heap[v] = 1

    # ---------------------------------------------------------
    # Output
    # First line: R C
    # Then modified matrix.
    # ---------------------------------------------------------
    out = [f"{R} {C}"]

    for row in modified:
        out.append(" ".join(map(str, row)))

    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    solve()
