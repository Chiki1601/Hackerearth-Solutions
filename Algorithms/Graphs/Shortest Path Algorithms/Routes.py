# Write your code here
from collections import defaultdict
from heapq import heappop, heappush
 
 
def find_shortest_path(graph, start, length, amount, parent):
    visited = [False] * length
    distance = [float('inf')] * length
    distance[start] = 0
    heap = [(0, start)]
    while heap:
        cost, node = heappop(heap)
        if not visited[node]:
            visited[node] = True
            for next_node, next_time, next_price in graph[node]:
                if node != start:
                    next_time += 1
                new_cost = next_time * amount + next_price
                if distance[next_node] > distance[node] + new_cost:
                    distance[next_node] = distance[node] + new_cost
                    heappush(heap, (distance[next_node], next_node))
                    parent[next_node] = (node, next_time)
    return distance
 
 
k = int(input())
n = int(input())
x = int(input())
if not (1 <= k <= 1000 and 1 <= x <= (n * (n - 1)) // 2):
    print('Error')
else:
    routes = defaultdict(list)
    for _ in range(x):
        a, b, t, c = map(int, input().strip().split())
        a -= 1
        b -= 1
        routes[a].append((b, t, c))
        routes[b].append((a, t, c))
    s = int(input())
    d = int(input())
    s -= 1
    d -= 1
    parents = [()] * n
    dist = find_shortest_path(routes, s, n, k, parents)
    if dist[d] == float('inf'):
        print('Error')
    else:
        path = []
        total_time = 0
        curr = (d, 0)
        while curr:
            path.append(curr[0] + 1)
            total_time += curr[1]
            curr = parents[curr[0]]
        print('->'.join(map(str, path[::-1])), total_time, dist[d])
