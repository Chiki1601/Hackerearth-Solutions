# Write your code here
n, x, m = map(int, input().strip().split())
paths = []
for _ in range(m):
    u, v, w = map(int, input().strip().split())
    u -= 1
    v -= 1
    paths.append((w, u, v))
 
 
def find(x, p):
    while x != p[x]:
        p[x] = p[p[x]]
        x = p[x]
    return x
 
 
def union(x, y, p, r):
    px = find(x, p)
    py = find(y, p)
    if r[px] > r[py]:
        p[py] = px
    else:
        p[px] = py
        r[py] += (r[px] == r[py])
 
 
def kruskal(adj, size):
    parent = [i for i in range(size)]
    rank = [0] * size
    adj.sort()
    dist = []
    for c, a, b in adj:
        if find(a, parent) != find(b, parent):
            union(a, b, parent, rank)
            dist.append(c)
    return dist
 
 
print(max(kruskal(paths, n)))
