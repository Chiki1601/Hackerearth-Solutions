n, m = map(int, input().strip().split())
g = [0] * n
for _ in range(m):
    v, u, w = map(int, input().strip().split())
    g[v - 1] += w
    g[u - 1] -= w
print(sum(i for i in g if i > 0))
