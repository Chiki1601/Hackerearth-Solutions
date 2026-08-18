import sys

input = sys.stdin.buffer.readline


def solve():
    n = int(input())

    if n == 1:
        print("1 1")
        return

    g = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)

    # ---------------------------------------------------------
    # Root the tree at node 0
    # ---------------------------------------------------------
    parent = [-1] * n
    order = [0]

    for u in order:
        for v in g[u]:
            if v == parent[u]:
                continue
            parent[v] = u
            order.append(v)

    # ---------------------------------------------------------
    # For every node:
    #
    # down[u]     = maximum distance from u into its subtree
    # down_cnt[u] = number of endpoints achieving that distance
    #
    # child best information:
    #
    # b1d  = best child-branch distance
    # b1c  = total number of endpoints at that distance
    # b1sq = sum(count_of_each_branch^2)
    #
    # b2d  = second different child-branch distance
    # b2c  = number of endpoints at that distance
    # ---------------------------------------------------------

    down = [0] * n
    down_cnt = [1] * n

    b1d = [-1] * n
    b1c = [0] * n
    b1sq = [0] * n

    b2d = [-1] * n
    b2c = [0] * n

    for u in reversed(order):

        first_d = -1
        first_c = 0
        first_sq = 0

        second_d = -1
        second_c = 0

        for v in g[u]:
            if parent[v] != u:
                continue

            d = down[v] + 1
            c = down_cnt[v]

            if d > first_d:
                second_d = first_d
                second_c = first_c

                first_d = d
                first_c = c
                first_sq = c * c

            elif d == first_d:
                first_c += c
                first_sq += c * c

            elif d > second_d:
                second_d = d
                second_c = c

            elif d == second_d:
                second_c += c

        b1d[u] = first_d
        b1c[u] = first_c
        b1sq[u] = first_sq

        b2d[u] = second_d
        b2c[u] = second_c

        if first_d == -1:
            down[u] = 0
            down_cnt[u] = 1
        else:
            down[u] = first_d
            down_cnt[u] = first_c

    # ---------------------------------------------------------
    # Rerooting:
    #
    # up[u]     = maximum distance from u to a vertex outside
    #             subtree(u)
    #
    # up_cnt[u] = number of such vertices
    # ---------------------------------------------------------

    up = [-1] * n
    up_cnt = [0] * n

    for u in order:

        for v in g[u]:
            if parent[v] != u:
                continue

            # From v, node u itself is always available.
            best_d = 1
            best_c = 1

            # Branch through another child of u.
            v_branch_d = down[v] + 1

            if b1d[u] != -1:

                if b1d[u] == v_branch_d:

                    # Remove v's contribution from the best group.
                    remaining = b1c[u] - down_cnt[v]

                    if remaining > 0:
                        cand_d = b1d[u] + 1
                        cand_c = remaining

                    elif b2d[u] != -1:
                        cand_d = b2d[u] + 1
                        cand_c = b2c[u]

                    else:
                        cand_d = -1
                        cand_c = 0

                else:
                    cand_d = b1d[u] + 1
                    cand_c = b1c[u]

                if cand_d > best_d:
                    best_d = cand_d
                    best_c = cand_c

                elif cand_d == best_d:
                    best_c += cand_c

            # Parent-side branch.
            if up[u] != -1:

                cand_d = up[u] + 1
                cand_c = up_cnt[u]

                if cand_d > best_d:
                    best_d = cand_d
                    best_c = cand_c

                elif cand_d == best_d:
                    best_c += cand_c

            up[v] = best_d
            up_cnt[v] = best_c

    # ---------------------------------------------------------
    # Find answer for every vertex.
    #
    # Each vertex has several branches:
    #
    #   1. The vertex itself: distance 0, count 1
    #   2. Every child subtree
    #   3. The parent-side subtree
    #
    # A longest path through u uses two different branches.
    # ---------------------------------------------------------

    answer = []

    for u in range(n):

        # Start with the branch consisting of u itself.
        first_d = 0
        first_c = 1
        first_sq = 1

        second_d = -1
        second_c = 0

        # Helper to add a branch group.
        def add_group(d, c, sq=None):
            nonlocal first_d, first_c, first_sq
            nonlocal second_d, second_c

            if d < 0:
                return

            if d > first_d:

                second_d = first_d
                second_c = first_c

                first_d = d
                first_c = c

                if sq is None:
                    first_sq = c * c
                else:
                    first_sq = sq

            elif d == first_d:

                first_c += c

                if sq is None:
                    first_sq += c * c
                else:
                    first_sq += sq

            elif d > second_d:

                second_d = d
                second_c = c

            elif d == second_d:

                second_c += c

        # Best child branch group.
        if b1d[u] != -1:
            add_group(b1d[u], b1c[u], b1sq[u])

        # Second child branch group.
        if b2d[u] != -1:
            add_group(b2d[u], b2c[u])

        # Parent-side branch.
        if up[u] != -1:
            add_group(up[u], up_cnt[u])

        # -----------------------------------------------------
        # If there are at least two different branches having
        # the maximum distance, the longest path connects them.
        #
        # first_c = total endpoints across those branches
        # first_sq = sum(c*c) for individual branches
        #
        # Number of pairs from DIFFERENT branches:
        #
        # (first_c^2 - sum(c^2)) / 2
        # -----------------------------------------------------

        same_depth_pairs = (first_c * first_c - first_sq) // 2

        if same_depth_pairs > 0:

            # Two maximum branches.
            length = 2 * first_d + 1
            count = same_depth_pairs

        elif second_d >= 0:

            # Only one branch has maximum depth.
            # Pair it with the best different-depth branch.
            length = first_d + second_d + 1
            count = first_c * second_c

        else:

            # Single node tree.
            length = 1
            count = 1

        answer.append((length, count))

    # ---------------------------------------------------------
    # Output
    # ---------------------------------------------------------

    out = []

    for length, count in answer:
        out.append(f"{length} {count}")

    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    solve()
