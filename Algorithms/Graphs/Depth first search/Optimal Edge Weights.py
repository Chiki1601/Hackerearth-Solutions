from collections import defaultdict
 
 
def assign_toll_taxes(x, number_cities, adjacency, visited, taxes):
    visited[x] = True
    res = 0
    for y in adjacency[x]:
        if not visited[y]:
            val = assign_toll_taxes(y, number_cities, adjacency, visited, taxes)
            taxes.append((number_cities - val) * val)
            res += val
    return res + 1
 
 
n, _ = map(int, input().strip().split())
tree = defaultdict(set)
for _ in range(n):
    u, v = map(int, input().strip().split())
    u -= 1
    v -= 1
    tree[u].add(v)
    tree[v].add(u)
a = list(map(int, input().strip().split()))
tolls = []
assign_toll_taxes(0, n + 1, tree, [False] * (n + 1), tolls)
a.sort()
tolls.sort()
ans = 0
for city, toll in zip(a, tolls):
    ans += city * toll
print(ans)
