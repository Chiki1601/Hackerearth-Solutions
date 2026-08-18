import sys

input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))

edges = []
graph = [[] for _ in range(N)]

for eid in range(N - 1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1

    edges.append((u, v))
    graph[u].append((v, eid))
    graph[v].append((u, eid))


def weight(a, b):
    return (a ^ b) * (a | b)


# Initial edge weights
ew = [0] * (N - 1)
total = 0

for eid, (u, v) in enumerate(edges):
    ew[eid] = weight(A[u], A[v])
    total += ew[eid]


def gain_for_swap(u, v):
    """
    Gain in total edge weight if A[u] and A[v] are swapped.
    """

    x = A[u]
    y = A[v]

    gain = 0

    for w, eid in graph[u]:
        if w != v:
            gain += weight(y, A[w]) - ew[eid]

    for w, eid in graph[v]:
        if w != u:
            gain += weight(x, A[w]) - ew[eid]

    return gain


# ---------------------------------------------------------
# Instead of checking every edge repeatedly, use only
# promising edges.
# ---------------------------------------------------------

candidate = list(range(N - 1))

candidate.sort(
    key=lambda eid: ew[eid],
    reverse=True
)

# Small enough for the 1 second limit.
candidate = candidate[:min(1000, N - 1)]


best_score = total * (K + 1)
best_operations = []

operations = []

for _ in range(K):

    best_gain = 0
    best_eid = -1

    for eid in candidate:
        u, v = edges[eid]

        gain = gain_for_swap(u, v)

        if gain > best_gain:
            best_gain = gain
            best_eid = eid

    if best_eid == -1:
        break

    u, v = edges[best_eid]

    # Swap node values
    A[u], A[v] = A[v], A[u]

    # Update affected edges
    affected = set()

    for w, eid in graph[u]:
        affected.add(eid)

    for w, eid in graph[v]:
        affected.add(eid)

    for eid in affected:
        total -= ew[eid]

    for eid in affected:
        a, b = edges[eid]
        ew[eid] = weight(A[a], A[b])
        total += ew[eid]

    operations.append((u + 1, v + 1))

    x = len(operations)

    score = total * (K - x + 1)

    if score > best_score:
        best_score = score
        best_operations = operations.copy()


print(len(best_operations))

for u, v in best_operations:
    print(u, v)
