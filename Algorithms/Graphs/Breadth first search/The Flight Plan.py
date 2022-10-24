# Write your code here
from collections import defaultdict, deque
 
 
def bfs(from_city, to_city, nodes, adjacency):
    queue = deque()
    queue.append(from_city)
    visited = [False] * nodes
    visited[from_city - 1] = True
    parent = {from_city: -1}
    while queue:
        cur_city = queue.popleft()
        adjacency[cur_city].sort()
        for next_city in adjacency[cur_city]:
            if not visited[next_city - 1]:
                visited[next_city - 1] = True
                queue.append(next_city)
                parent[next_city] = cur_city
            if next_city == to_city:
                path = []
                val = to_city
                while val != -1:
                    path.append(val)
                    val = parent[val]
                return path
 
 
n, m, t, c = map(int, input().strip().split())
cities = defaultdict(list)
for _ in range(m):
    u, v = map(int, input().split())
    cities[u].append(v)
    cities[v].append(u)
x, y = map(int, input().strip().split())
if x == y:
    print('1\n1')
else:
    res = bfs(x, y, n, cities)
    print(len(res))
    print(*res[::-1])
