# Write your code here
from collections import defaultdict
from math import ceil
 
 
def find_path(u, v, w, adj, paths, path=None):
    if path is None:
        path = []
    if u in path:
        return
    else:
        path.append(u)
    if v in adj[u]:
        path.append(v)
        w = min(w, adj[u][v])
        new_path = [w] + path
        paths.append(new_path)
        return
    for i in adj[u]:
        if i in adj:
            find_path(i, v, min(w, adj[u][i]), adj, paths, path[:])
 
 
n, r = map(int, input().strip().split())
roads = defaultdict(dict)
for _ in range(r):
    c1, c2, p = map(int, input().strip().split())
    p -= 1
    roads[c1][c2] = p
    roads[c2][c1] = p
s, d, t = map(int, input().strip().split())
ans = []
find_path(s, d, float('inf'), roads, ans)
ans.sort()
print(*ans[-1][1:])
print(ceil(t / ans[-1][0]))
