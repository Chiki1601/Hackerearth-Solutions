# Write your code here
from collections import defaultdict
from heapq import heappush, heappop
from sys import stdin
 
 
def dijkstra(adj, capacities, length, total_vehicles):
    visited = [False] * (length + 1)
    dist = [float('inf')] * (length + 1)
    dist[1] = 0
    parking = []
    sum_capacity = 0
    heap = [(0, 1)]
    while heap:
        cost, node = heappop(heap)
        if not visited[node]:
            visited[node] = True
            capacity = capacities[node]
            sum_capacity += capacity
            parking.append((node, cost, capacity))
            if sum_capacity >= total_vehicles:
                break
            for next_node, next_cost in adj[node]:
                if not visited[next_node]:
                    new_cost = cost + next_cost
                    if dist[next_node] > new_cost:
                        heappush(heap, (new_cost, next_node))
                        dist[next_node] = new_cost
    return parking
 
 
n, m, f = map(int, stdin.readline().strip().split())
c = [0] + list(map(int, stdin.readline().strip().split()))
graph = defaultdict(list)
for _ in range(m):
    u, v, w = map(int, stdin.readline().strip().split())
    graph[u].append((v, w))
    graph[v].append((u, w))
k = int(stdin.readline())
i = 0
ans = []
park = dijkstra(graph, c, n, k)
while k:
    if i == len(park):
        ans += [-1] * k
        break
    idx, unit, tot = park[i]
    if k <= tot:
        ans += [f + unit] * k
        break
    else:
        ans += [f + unit] * tot
        k -= tot
        i += 1
print(*ans)
