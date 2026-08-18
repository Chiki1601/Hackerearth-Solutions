import sys

input = sys.stdin.buffer.readline


# ------------------------------------------------------------
# Read input
# ------------------------------------------------------------

N, Q = map(int, input().split())

graph = [[] for _ in range(N)]

for _ in range(N - 1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1

    graph[u].append(v)
    graph[v].append(u)


# ------------------------------------------------------------
# Binary lifting
# ------------------------------------------------------------

LOG = N.bit_length()

parent = [0] * N
depth = [0] * N
order = [0]

parent[0] = 0

# Iterative DFS
for v in order:
    for to in graph[v]:
        if to == parent[v]:
            continue

        parent[to] = v
        depth[to] = depth[v] + 1
        order.append(to)


# ------------------------------------------------------------
# Subtree sizes + original tree answer
#
# For every tree edge:
#
#       subtree_size * (N - subtree_size)
#
# is the number of unordered vertex pairs whose path uses
# that edge.
# ------------------------------------------------------------

subtree = [1] * N

original_answer = 0

for v in reversed(order[1:]):
    p = parent[v]

    original_answer += subtree[v] * (N - subtree[v])

    subtree[p] += subtree[v]


# ------------------------------------------------------------
# Binary lifting table
# ------------------------------------------------------------

up = [parent]

for k in range(1, LOG):
    prev = up[-1]

    cur = [0] * N

    for v in range(N):
        cur[v] = prev[prev[v]]

    up.append(cur)


# ------------------------------------------------------------
# Move x upward by d
# ------------------------------------------------------------

def shift(x, d):

    bit = 0

    while d:
        if d & 1:
            x = up[bit][x]

        d >>= 1
        bit += 1

    return x


# ------------------------------------------------------------
# LCA
# ------------------------------------------------------------

def lca(a, b):

    if depth[a] > depth[b]:
        a = shift(a, depth[a] - depth[b])

    elif depth[b] > depth[a]:
        b = shift(b, depth[b] - depth[a])

    if a == b:
        return a

    for k in range(LOG - 1, -1, -1):

        if up[k][a] != up[k][b]:
            a = up[k][a]
            b = up[k][b]

    return parent[a]


# ------------------------------------------------------------
# Calculate contribution of a cycle.
#
# s[i] = number of original vertices belonging to the
# component attached to cycle vertex i.
#
# The distance between cycle vertices i and j is:
#
#       min(j-i, size-(j-i))
#
# ------------------------------------------------------------

def cycle_sum(values):

    m = len(values)

    if m <= 1:
        return 0

    # 1-indexed arrays, matching the original solution.
    s = [0] + values

    prefix_sum = [0] * (m + 1)
    prefix_index_sum = [0] * (m + 1)
    prefix_reverse_sum = [0] * (m + 1)

    for i in range(1, m + 1):

        x = s[i]

        prefix_sum[i] = (
            prefix_sum[i - 1] + x
        )

        prefix_index_sum[i] = (
            prefix_index_sum[i - 1]
            + i * x
        )

        prefix_reverse_sum[i] = (
            prefix_reverse_sum[i - 1]
            + (m - i + 1) * x
        )

    answer = 0

    d = (m - 1) // 2

    for i in range(1, m + 1):

        nxt = min(m, i + d)

        # Clockwise direction is shorter.
        #
        # distance = j - i
        #
        answer += s[i] * (
            prefix_index_sum[nxt]
            - prefix_index_sum[i]
            - i * (
                prefix_sum[nxt]
                - prefix_sum[i]
            )
        )

        # Counter-clockwise direction is shorter.
        if i + d < m:

            answer += s[i] * (
                prefix_reverse_sum[m]
                - prefix_reverse_sum[nxt]
                + (i - 1) * (
                    prefix_sum[m]
                    - prefix_sum[nxt]
                )
            )

    return answer


# ------------------------------------------------------------
# Queries
# ------------------------------------------------------------

result = []

for _ in range(Q):

    u, v = map(int, input().split())

    u -= 1
    v -= 1

    w = lca(u, v)

    # Make u the shallower vertex.
    if depth[u] > depth[v]:
        u, v = v, u

    answer = original_answer

    components = []

    # --------------------------------------------------------
    # Case 1:
    #
    # u is LCA(u,v)
    #
    # Path:
    #
    # u -> ... -> v
    # --------------------------------------------------------

    if u == w:

        a = v

        components.append(subtree[a])

        while a != w:

            # The edge parent[a] - a becomes part of the cycle.
            # Remove its old tree contribution.
            answer -= (
                subtree[a]
                * (N - subtree[a])
            )

            p = parent[a]

            # Component attached to p after removing the
            # path edge.
            components.append(
                subtree[p] - subtree[a]
            )

            a = p

        # At the LCA, everything except the child subtree
        # containing v belongs to this component.
        child = shift(
            v,
            depth[v] - depth[w] - 1
        )

        components[-1] = N - subtree[child]

    # --------------------------------------------------------
    # Case 2:
    #
    # LCA is strictly between u and v.
    # --------------------------------------------------------

    else:

        a = v
        b = u

        X = []
        Y = []

        # v-side
        X.append(subtree[a])

        while a != w:

            answer -= (
                subtree[a]
                * (N - subtree[a])
            )

            p = parent[a]

            X.append(
                subtree[p] - subtree[a]
            )

            a = p

        # u-side
        Y.append(subtree[b])

        while b != w:

            answer -= (
                subtree[b]
                * (N - subtree[b])
            )

            p = parent[b]

            Y.append(
                subtree[p] - subtree[b]
            )

            b = p

        # The LCA was added to both lists.
        X.pop()
        Y.pop()

        # Reverse u-side so the path is continuous.
        Y.reverse()

        components.extend(X)

        # Component belonging to the LCA.
        child_v = shift(
            v,
            depth[v] - depth[w] - 1
        )

        child_u = shift(
            u,
            depth[u] - depth[w] - 1
        )

        components.append(
            N
            - subtree[child_v]
            - subtree[child_u]
        )

        components.extend(Y)

    # --------------------------------------------------------
    # Add the distances around the newly created cycle.
    # --------------------------------------------------------

    answer += cycle_sum(components)

    result.append(str(answer))


sys.stdout.write("\n".join(result))
