# Write your code here
t = int(input())
 
 
def find(x, p):
    while p[x] != x:
        p[x] = p[p[x]]
        x = p[x]
    return x
 
 
def union(x, y, p, r):
    px = find(x, p)
    py = find(y, p)
    if r[px] > r[py]:
        p[py] = p[px]
        r[px] += r[py]
    else:
        p[px] = p[py]
        r[py] += r[px]
 
 
for _ in range(t):
    n, m = map(int, input().strip().split())
    roads = []
    for _ in range(m):
        a, b, c = map(int, input().strip().split())
        if a < b:
            a, b = b, a
        roads.append((a, b, c))
    roads.sort(key=lambda x: (x[-1], -x[1], -x[0]))
    parents = [i for i in range(n + 1)]
    ranks = [0] * (n + 1)
    degree_sequence = [0] * (n + 1)
    min_cost = 0
    for a, b, c in roads:
        if find(a, parents) != find(b, parents):
            min_cost += c
            degree_sequence[a] += 1
            degree_sequence[b] += 1
            union(a, b, parents, ranks)
    print(min_cost)
    print(*map(str, degree_sequence[1:]))
