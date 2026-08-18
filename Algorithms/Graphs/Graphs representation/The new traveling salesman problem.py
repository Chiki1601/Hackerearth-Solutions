import sys

input = sys.stdin.readline

N, M = map(int, input().split())

# adjacency list:
# (neighbor, road_id)
graph = [[] for _ in range(N)]

for road_id in range(1, M + 1):
    u, v, c, g = map(int, input().split())

    u -= 1
    v -= 1

    graph[u].append((v, road_id))
    graph[v].append((u, road_id))


# ---------------------------------------------------------
# DFS spanning tree
# ---------------------------------------------------------
visited = [False] * N
visited[0] = True

answer = []

# Stack frame:
# [node, parent_edge, next_edge_index]
stack = [[0, -1, 0]]

while stack:

    u, parent_edge, idx = stack[-1]

    # Finished exploring this node
    if idx == len(graph[u]):
        stack.pop()

        # Return to parent using the same road
        if parent_edge != -1:
            answer.append(parent_edge)

        continue

    # Move to next adjacent road
    v, road_id = graph[u][idx]
    stack[-1][2] += 1

    if visited[v]:
        continue

    # Visit new city
    visited[v] = True

    # Go from u -> v
    answer.append(road_id)

    # Explore v
    stack.append([v, road_id, 0])


# ---------------------------------------------------------
# Output
# ---------------------------------------------------------
print(len(answer))
print(*answer)
