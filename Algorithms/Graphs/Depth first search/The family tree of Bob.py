import sys

input = sys.stdin.buffer.readline

# N = number of nodes
# Q = number of queries
N, Q = map(int, input().split())

# Binary lifting table
# LOG is enough to represent k <= 5 * 10^5
LOG = (N).bit_length()

up = [[0] * (N + 1) for _ in range(LOG)]

# ---------------------------------------------------------
# Read edges
#
# The statement gives an edge between u and v, but doesn't
# explicitly state parent -> child. So we first build an
# undirected tree and root it at node 1.
# ---------------------------------------------------------

graph = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)


# ---------------------------------------------------------
# Root tree at 1
# ---------------------------------------------------------

parent = [0] * (N + 1)
parent[1] = 0

stack = [1]

while stack:
    u = stack.pop()

    for v in graph[u]:
        if v == parent[u]:
            continue

        parent[v] = u
        stack.append(v)


# First ancestor
for i in range(1, N + 1):
    up[0][i] = parent[i]


# ---------------------------------------------------------
# Build binary lifting table
#
# up[j][u] = 2^j-th ancestor of u
# ---------------------------------------------------------

for j in range(1, LOG):
    prev = up[j - 1]
    curr = up[j]

    for i in range(1, N + 1):
        curr[i] = prev[prev[i]]


# ---------------------------------------------------------
# Answer queries
# ---------------------------------------------------------

out = []

for _ in range(Q):
    u, k = map(int, input().split())

    # If k is larger than possible depth, answer -1.
    # We can simply perform binary lifting; reaching 0
    # means the ancestor does not exist.

    current = u

    bit = 0

    while k and current != 0:
        if k & 1:
            current = up[bit][current]

        k >>= 1
        bit += 1

    if current == 0:
        out.append("-1")
    else:
        out.append(str(current))


sys.stdout.write("\n".join(out))
