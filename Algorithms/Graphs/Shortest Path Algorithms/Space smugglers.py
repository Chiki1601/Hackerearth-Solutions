from collections import defaultdict
from heapq import heappop, heappush
 
 
def dijkstra(start, adj, size):
    distances = [float('inf')] * (size + 1)
    distances[start] = 0
    heap = [(0, start)]
    visited = [False] * (size + 1)
    while heap:
        _, node = heappop(heap)
        if not visited[node]:
            visited[node] = True
            for next_node, next_cost in adj[node]:
                distances[next_node] = min(distances[next_node], distances[node] + next_cost)
                heappush(heap, (distances[next_node], next_node))
    return distances
 
 
n, m, s, t = map(int, input().strip().split())
tunnels = defaultdict(list)
reverse_tunnels = defaultdict(list)
for _ in range(m):
    u, v, g = map(int, input().split())
    tunnels[u].append((v, g))
    reverse_tunnels[v].append((u, g))
dist1 = dijkstra(s, tunnels, n)
dist2 = dijkstra(s, reverse_tunnels, n)
dist3 = dijkstra(t, tunnels, n)
dist4 = dijkstra(t, reverse_tunnels, n)
ans = float('inf')
for i in range(1, n + 1):
    if i != s and i != t:
        ans = min(ans, dist1[i] + dist2[i] + dist3[i] + dist4[i])
print(-1 if ans == float('inf') else ans)
