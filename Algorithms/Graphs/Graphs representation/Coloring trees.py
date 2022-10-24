# Write your code here
from collections import defaultdict
 
n, k = map(int, input().strip().split())
graph = defaultdict(set)
for i in range(n - 1):
    u, v = map(int, input().strip().split())
    graph[u].add(v)
    graph[v].add(u)
terminals = set(map(int, input().split()))
if len(terminals) < 2:
    print(0)
else:
    def dfs(city, adj, cache, crowded):
        cache[city] = True
        for connected_city in adj[city]:
            if not cache[connected_city]:
                res = dfs(connected_city, adj, cache, crowded)
                if res and not crowded[city]:
                    crowded[city] = True
        return crowded[city]
 
 
    visited = [False] * (n + 1)
    crowded_cities = [False] * (n + 1)
    for terminal in terminals:
        crowded_cities[terminal] = True
    for terminal in terminals:
        if not visited[terminal]:
            dfs(terminal, graph, visited, crowded_cities)
    print(crowded_cities.count(True))
