import sys
from collections import deque

input = sys.stdin.readline

N, M, P = map(int, input().split())

graph = [[] for _ in range(N + 1)]

for _ in range(P):
    u, v = map(int, input().split())
    graph[u].append(v)


# pair_left[u]  = right vertex matched with u
# pair_right[v] = left vertex matched with v
pair_left = [0] * (N + 1)
pair_right = [0] * (M + 1)

dist = [0] * (N + 1)


def bfs():
    q = deque()

    for u in range(1, N + 1):
        if pair_left[u] == 0:
            dist[u] = 0
            q.append(u)
        else:
            dist[u] = -1

    found = False

    while q:
        u = q.popleft()

        for v in graph[u]:
            next_u = pair_right[v]

            if next_u == 0:
                found = True
            elif dist[next_u] == -1:
                dist[next_u] = dist[u] + 1
                q.append(next_u)

    return found


def dfs(u):
    for v in graph[u]:
        next_u = pair_right[v]

        if next_u == 0 or (
            dist[next_u] == dist[u] + 1 and dfs(next_u)
        ):
            pair_left[u] = v
            pair_right[v] = u
            return True

    dist[u] = -1
    return False


matching = 0

while bfs():
    for u in range(1, N + 1):
        if pair_left[u] == 0:
            if dfs(u):
                matching += 1


print(matching)
