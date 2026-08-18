import sys
import random

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

# ---------------------------------------------------------
# Score a chain:
#
# chain = [1, ...]
#
# For i < j:
# distance = j - i
# LCA = chain[i]
#
# F = (distance XOR A[lca]) + distance * A[lca]
# ---------------------------------------------------------

def chain_score(order):
    score = 0

    # order is 0-based node numbers
    for i in range(N):
        a = A[order[i]]

        for j in range(i + 1, N):
            d = j - i
            score += (d ^ a) + d * a

    return score


# ---------------------------------------------------------
# Generate candidate orders.
# Node 1 MUST be the root.
# ---------------------------------------------------------

nodes = list(range(1, N))


candidates = []

# 1. Descending A
order = [0] + sorted(nodes, key=lambda x: A[x], reverse=True)
candidates.append(order)

# 2. Ascending A
order = [0] + sorted(nodes, key=lambda x: A[x])
candidates.append(order)

# 3. Descending by A, but alternating high/low
sorted_nodes = sorted(nodes, key=lambda x: A[x], reverse=True)

left = 0
right = len(sorted_nodes) - 1
temp = []

while left <= right:
    if left <= right:
        temp.append(sorted_nodes[left])
        left += 1

    if left <= right:
        temp.append(sorted_nodes[right])
        right -= 1

candidates.append([0] + temp)


# 4. High A first, but keep node 1 fixed
order = sorted(
    nodes,
    key=lambda x: (A[x], -x),
    reverse=True
)
candidates.append([0] + order)


# 5. Low A first
order = sorted(
    nodes,
    key=lambda x: (A[x], x)
)
candidates.append([0] + order)


# ---------------------------------------------------------
# Random candidates
# ---------------------------------------------------------

random.seed(123456789)

for _ in range(20):
    order = nodes[:]
    random.shuffle(order)

    candidates.append([0] + order)


# ---------------------------------------------------------
# Find best chain
# ---------------------------------------------------------

best_score = -1
best_order = None

for order in candidates:
    score = chain_score(order)

    if score > best_score:
        best_score = score
        best_order = order


# ---------------------------------------------------------
# Also try a star.
#
# Root = 1
# Every other node is directly connected to 1.
# ---------------------------------------------------------

star_order = [0] + nodes

star_score = 0

# Root-other pairs
for j in range(1, N):
    d = 1
    a = A[0]

    star_score += (d ^ a) + d * a

# Other-other pairs
for i in range(1, N):
    for j in range(i + 1, N):
        d = 2
        a = A[0]

        star_score += (d ^ a) + d * a

if star_score > best_score:
    best_score = star_score

    # For a star, the order is irrelevant.
    best_order = None


# ---------------------------------------------------------
# Output
# ---------------------------------------------------------

if best_order is None:
    # Star rooted at node 1
    for v in range(2, N + 1):
        print(1, v)

else:
    # Chain:
    #
    # best_order[0] = 1
    # best_order[1] -> child of 1
    # best_order[2] -> child of best_order[1]
    # ...
    for i in range(1, N):
        print(best_order[i - 1] + 1, best_order[i] + 1)
