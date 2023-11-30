from collections import defaultdict
from heapq import heappush, heappop

n, m, k, c = map(int, input().strip().split())
c -= 1
roads = defaultdict(list)
for _ in range(m):
    u, v = map(lambda x: int(x) - 1, input().strip().split())
    roads[u].append(v)
    roads[v].append(u)
dist = [-1] * n
heap = [(0, c)]
while heap:
    d, u = heappop(heap)
    if dist[u] == -1:
        dist[u] = d
        for v in roads[u]:
            if dist[v] == -1:
                heappush(heap, (d + 1, v))
cnt = 0
for i in dist:
    if i != -1 and i <= k:
        cnt += 1
print(cnt)
