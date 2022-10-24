# Write your code here
from collections import defaultdict
from heapq import heappush, heappop
 
 
def find_shortest_path(total, offer, adj):
    dp = [[float('inf')] * (offer + 1) for _ in range(total + 1)]
    dp[1] = [0] * (offer + 1)
    heap = []
    heappush(heap, (0, 1, 0))
    while heap:
        _, node, parent = heappop(heap)
        for next_node, charge in adj[node]:
            if next_node != parent:
                flag = False
                for i in range(offer + 1):
                    if i == 0 and dp[next_node][i] > dp[node][i] + charge:
                        dp[next_node][i] = min(dp[next_node][i], dp[node][i] + charge)
                        flag = True
                    elif i != 0 and dp[next_node][i] > dp[node][i - 1] or dp[next_node][i] > dp[node][i] + charge:
                        dp[next_node][i] = min(dp[node][i - 1], dp[node][i] + charge)
                        flag = True
                if flag:
                    heappush(heap, (min(dp[next_node]), next_node, node))
    return dp
 
 
n, m, k = map(int, input().strip().split())
roads = defaultdict(list)
for _ in range(m):
    u, v, w = map(int, input().strip().split())
    roads[u].append((v, w))
    roads[v].append((u, w))
res = find_shortest_path(n, k, roads)
print(*(min(res[i]) for i in range(1, n + 1)))
