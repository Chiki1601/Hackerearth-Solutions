import sys
import random

input = sys.stdin.buffer.readline

# ------------------------------------------------------------
# Input
# ------------------------------------------------------------
N, K = map(int, input().split())
A = [0] + list(map(int, input().split()))

graph = [[] for _ in range(N + 1)]
edges = []

for _ in range(N - 1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
    edges.append((u, v))


# ------------------------------------------------------------
# Edge weight
# ------------------------------------------------------------
def edge_weight(a, b):
    return (a + b) * (a | b)


# ------------------------------------------------------------
# Initial total edge weight
# ------------------------------------------------------------
base_sum = 0

for u, v in edges:
    base_sum += edge_weight(A[u], A[v])


# ------------------------------------------------------------
# Root the tree at 1
# ------------------------------------------------------------
parent = [0] * (N + 1)
depth = [0] * (N + 1)

order = [1]
parent[1] = -1

for u in order:
    for v in graph[u]:
        if v == parent[u]:
            continue
        parent[v] = u
        depth[v] = depth[u] + 1
        order.append(v)

parent[1] = 0


# ------------------------------------------------------------
# Binary lifting
# ------------------------------------------------------------
LOG = N.bit_length()

up = [[0] * (N + 1) for _ in range(LOG)]

for i in range(1, N + 1):
    up[0][i] = parent[i]

for j in range(1, LOG):
    prev = up[j - 1]
    cur = up[j]

    for i in range(1, N + 1):
        cur[i] = prev[prev[i]]


# ------------------------------------------------------------
# LCA
# ------------------------------------------------------------
def lca(a, b):
    if depth[a] < depth[b]:
        a, b = b, a

    diff = depth[a] - depth[b]
    bit = 0

    while diff:
        if diff & 1:
            a = up[bit][a]
        diff >>= 1
        bit += 1

    if a == b:
        return a

    for j in range(LOG - 1, -1, -1):
        if up[j][a] != up[j][b]:
            a = up[j][a]
            b = up[j][b]

    return parent[a]


# ------------------------------------------------------------
# Get path between u and v
# ------------------------------------------------------------
def get_path(u, v):
    w = lca(u, v)

    left = []
    right = []

    x = u
    while x != w:
        left.append(x)
        x = parent[x]

    left.append(w)

    x = v
    while x != w:
        right.append(x)
        x = parent[x]

    right.reverse()

    return left + right


# ------------------------------------------------------------
# Calculate total edge weight after reversing path
#
# We do NOT actually modify A.
#
# Edges completely inside the path keep the same weight because
# edge_weight(a,b) is symmetric.
#
# Only edges going from path -> outside can change.
# ------------------------------------------------------------
def evaluate_path(path):
    L = len(path)

    if L <= 1:
        return base_sum

    pos_value = {}

    # After reversing:
    # path[i] gets the old value of path[L-1-i]
    for i in range(L):
        pos_value[path[i]] = A[path[L - 1 - i]]

    delta = 0

    path_set = set(path)

    for u in path:
        new_u = pos_value[u]

        for v in graph[u]:

            if v in path_set:
                continue

            old_cost = edge_weight(A[u], A[v])
            new_cost = edge_weight(new_u, A[v])

            delta += new_cost - old_cost

    return base_sum + delta


# ------------------------------------------------------------
# Generate promising candidate nodes
# ------------------------------------------------------------

# Nodes sorted by value.
nodes = list(range(1, N + 1))

nodes.sort(key=lambda x: A[x])

# Take low and high value nodes.
take = min(N, 150)

low_nodes = nodes[:take]
high_nodes = nodes[-take:]

candidates = []

# High against low
for x in high_nodes:
    candidates.append(x)

for x in low_nodes:
    candidates.append(x)

# Leaves are especially useful because reversing paths between
# leaves changes values at useful boundary positions.
leaves = []

for i in range(1, N + 1):
    if len(graph[i]) == 1:
        leaves.append(i)

# Add leaves ordered by weight.
leaves.sort(key=lambda x: A[x])

if len(leaves) > 200:
    leaves = leaves[:100] + leaves[-100:]

candidates.extend(leaves)

# Remove duplicates.
candidates = list(set(candidates))


# ------------------------------------------------------------
# Build candidate pairs.
#
# We don't try all N^2 pairs.
# ------------------------------------------------------------
pairs = []

# Pair high-valued nodes with low-valued nodes.
for x in high_nodes[:80]:
    for y in low_nodes[:80]:
        if x != y:
            pairs.append((x, y))

# Pair leaves.
for i in range(len(leaves)):
    for j in range(i + 1, len(leaves)):
        if len(pairs) >= 15000:
            break
        pairs.append((leaves[i], leaves[j]))
    if len(pairs) >= 15000:
        break

# Random pairs give additional coverage.
random.seed(1234567)

for _ in range(min(5000, N * 2)):
    u = random.randint(1, N)
    v = random.randint(1, N)

    if u != v:
        pairs.append((u, v))


# ------------------------------------------------------------
# Find best single operation
# ------------------------------------------------------------
best_sum = base_sum
best_pair = None

seen = set()

for u, v in pairs:

    if u == v:
        continue

    if u > v:
        u, v = v, u

    key = (u, v)

    if key in seen:
        continue

    seen.add(key)

    path = get_path(u, v)

    new_sum = evaluate_path(path)

    if new_sum > best_sum:
        best_sum = new_sum
        best_pair = (u, v)


# ------------------------------------------------------------
# If no operation improves the edge sum, still perform a valid
# operation because the problem asks for operations.
#
# Pick two different nodes.
# ------------------------------------------------------------
if best_pair is None:

    if N >= 2:
        best_pair = (1, 2)

    else:
        # N is at least 2 according to the constraints.
        best_pair = None


# ------------------------------------------------------------
# Output
#
# X = 1
# Score multiplier = K - X + 1 = K
#
# This is a strong and safe approximate solution.
# ------------------------------------------------------------
if best_pair is None:
    print(0)
else:
    print(1)
    print(best_pair[0], best_pair[1])
