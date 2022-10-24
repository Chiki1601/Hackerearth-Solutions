# Write your code here
from heapq import heappush, heappop
 
INF = float('inf')
 
 
def floyd_warshall(graph):
    size = len(graph)
    distances = [[INF] * size for _ in range(size)]
    for idx, val in enumerate(graph):
        distances[idx][idx] = 0
        for amount, neighbor in val:
            distances[idx][neighbor] = amount
    for k in range(1, size):
        for i in range(1, size):
            for j in range(1, size):
                if distances[i][j] > distances[i][k] + distances[k][j]:
                    distances[i][j] = distances[i][k] + distances[k][j]
    return distances
 
 
def find_minimum_money(graph, start, end):
    heap = [(0, start)]
    while heap:
        cost, node = heappop(heap)
        if node == end:
            return cost
        for next_cost, next_node in graph[node]:
            heappush(heap, (next_cost + cost, next_node))
    return -1
 
 
n, m, s, e = map(int, input().strip().split())
telegraph = [[] for _ in range(n + 2)]
for _ in range(m):
    u, v, t = map(int, input().strip().split())
    telegraph[u].append((t, v))
min_cost = floyd_warshall(telegraph)
if min_cost[s][e] == INF or min_cost[e][s] == INF:
    print(-1)
else:
    for i, adj in enumerate(telegraph):
        for j, (t, v) in enumerate(adj):
            telegraph[i][j] = (t + min_cost[v][i], v)
    print(find_minimum_money(telegraph, s, e))
