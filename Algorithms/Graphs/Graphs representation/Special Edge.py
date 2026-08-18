import sys

sys.setrecursionlimit(300000)

input = sys.stdin.readline

N, M = map(int, input().split())

A = list(map(int, input().split()))

graph = [[] for _ in range(N)]

for edge_id in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1

    # Store edge id so parallel edges are handled correctly
    graph[u].append((v, edge_id))
    graph[v].append((u, edge_id))


tin = [-1] * N
low = [-1] * N

# Sum of A values in DFS subtree
subtree_sum = [0] * N

timer = 0
total_sum = sum(A)

best_strength = -1
best_edge = (N + 1, N + 1)


def dfs(u, parent_edge):
    global timer, best_strength, best_edge

    tin[u] = low[u] = timer
    timer += 1

    subtree_sum[u] = A[u]

    for v, edge_id in graph[u]:

        # Ignore the exact edge through which we entered u
        if edge_id == parent_edge:
            continue

        if tin[v] == -1:
            # Tree edge
            dfs(v, edge_id)

            subtree_sum[u] += subtree_sum[v]

            low[u] = min(low[u], low[v])

            # u-v is a bridge
            if low[v] > tin[u]:

                s = subtree_sum[v]
                other = total_sum - s

                strength = s * other

                a = min(u + 1, v + 1)
                b = max(u + 1, v + 1)

                if strength > best_strength:
                    best_strength = strength
                    best_edge = (a, b)

                elif strength == best_strength:
                    if (a, b) < best_edge:
                        best_edge = (a, b)

        else:
            # Back edge
            low[u] = min(low[u], tin[v])


dfs(0, -1)

print(best_edge[0], best_edge[1])
