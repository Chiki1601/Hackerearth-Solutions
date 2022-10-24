# Write your code here
from collections import defaultdict
from heapq import heappop, heappush
from sys import stdin
 
 
def dijkstra(adj):
    seen = set()
    dist = {1: 0}
    heap = [(0, 1)]
    while heap:
        total, node = heappop(heap)
        if node not in seen:
            seen.add(node)
            for next_node, weight in adj[node]:
                next_total = total + weight
                if next_node not in dist or next_total < dist[next_node]:
                    dist[next_node] = next_total
                    heappush(heap, (next_total, next_node))
    return dist
 
 
n, m = map(int, stdin.readline().strip().split())
edges = defaultdict(list)
for _ in range(m):
    u, v, w = map(int, stdin.readline().strip().split())
    edges[u].append((v, w))
    edges[v].append((u, w))
dists = dijkstra(edges)
visited = {n}
heaps = [(-dists[n], n)]
res = ['none'] * n
while heaps:
    _, u = heappop(heaps)
    if not heaps:
        res[u - 1] = 'all'
    else:
        res[u - 1] = 'some'
    for v, w in edges[u]:
        if v not in visited:
            if dists[v] + w == dists[u]:
                heappush(heaps, (-dists[v], v))
                visited.add(v)
res[0] = 'all'
print(*res, sep='\n')
