import sys

input = sys.stdin.readline

N, M = map(int, input().split())

A = list(map(int, input().split()))

edges = []
incident = [[] for _ in range(N)]

for i in range(M):
    u, v, w = map(int, input().split())

    u -= 1
    v -= 1

    # Actual cost of reconstructing this road
    cost = w + A[u] + A[v]

    edges.append((u, v, w, cost))

    incident[u].append(i)
    incident[v].append(i)


# ---------------------------------------------------------
# Step 1:
# For every city, choose its cheapest incident road.
# ---------------------------------------------------------

selected = [False] * M

for u in range(N):
    best_edge = incident[u][0]

    for eid in incident[u]:
        if edges[eid][3] < edges[best_edge][3]:
            best_edge = eid

    selected[best_edge] = True


# ---------------------------------------------------------
# Calculate how many selected roads touch each city.
# ---------------------------------------------------------

degree = [0] * N

for eid in range(M):
    if selected[eid]:
        u, v, w, cost = edges[eid]

        degree[u] += 1

        # For a self-loop, it still counts as one road
        # covering that city.
        if v != u:
            degree[v] += 1


# ---------------------------------------------------------
# Step 2:
# Remove redundant expensive roads.
#
# If both endpoints have another selected road,
# this road can be removed without leaving any city
# uncovered.
# ---------------------------------------------------------

selected_edges = [
    eid for eid in range(M)
    if selected[eid]
]

# Try expensive roads first.
selected_edges.sort(
    key=lambda eid: edges[eid][3],
    reverse=True
)

for eid in selected_edges:

    if not selected[eid]:
        continue

    u, v, w, cost = edges[eid]

    if u == v:
        # A self-loop is removable if this city has
        # another selected incident road.
        if degree[u] > 1:
            selected[eid] = False
            degree[u] -= 1

    else:
        # Ordinary edge can be removed if both endpoints
        # remain covered by another selected edge.
        if degree[u] > 1 and degree[v] > 1:
            selected[eid] = False
            degree[u] -= 1
            degree[v] -= 1


# ---------------------------------------------------------
# Output
# ---------------------------------------------------------

answer = []

for eid in range(M):
    if selected[eid]:
        answer.append(eid + 1)

print(len(answer), *answer)
