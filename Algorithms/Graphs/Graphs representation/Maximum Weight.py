import sys

def solve():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)

    try:
        n = next(it)
        m = next(it)
    except StopIteration:
        return

    w = [next(it) for _ in range(n)]

    graph = [[] for _ in range(n)]

    for _ in range(m):
        u = next(it) - 1
        v = next(it) - 1

        graph[u].append(v)

        if u != v:
            graph[v].append(u)

    degree = [len(graph[i]) for i in range(n)]

    # Vertices with self-loops must be selected.
    forced = [False] * n

    for u in range(n):
        for v in graph[u]:
            if u == v:
                forced[u] = True
                break

    total_weight = sum(w)

    best_cover = None
    best_value = 10**30

    # Try a few cheap greedy orderings.
    orderings = [
        sorted(range(n), key=lambda x: (w[x], degree[x])),
        sorted(range(n), key=lambda x: (degree[x], w[x])),
        sorted(range(n), key=lambda x: (w[x] // (degree[x] + 1), w[x])),
    ]

    for order in orderings:

        selected = [False] * n
        blocked = [False] * n

        independent_sum = 0
        independent_count = 0

        for u in order:

            if forced[u]:
                continue

            if blocked[u]:
                continue

            # Put u into the independent set.
            selected[u] = True
            independent_count += 1
            independent_sum += w[u]

            # Its neighbours cannot be selected.
            for v in graph[u]:
                blocked[v] = True

        cover_count = n - independent_count
        cover_sum = total_weight - independent_sum

        value = cover_count * cover_sum

        if value < best_value:
            best_value = value

            best_cover = [
                i + 1
                for i in range(n)
                if not selected[i]
            ]

    # Safety check: the complement of an independent set
    # is always a valid vertex cover.
    print(len(best_cover))
    print(*best_cover)


if __name__ == "__main__":
    solve()
