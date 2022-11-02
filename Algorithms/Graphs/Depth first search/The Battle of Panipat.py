# Write your code here
from collections import defaultdict
 
mod = 1000000007
 
 
def attack(x, adjacency, seen):
    seen[x] = True
    a, b = 1, 0
    for y in adjacency[x]:
        if not seen[y]:
            ra, rb = attack(y, adjacency, seen)
            a = (a * (ra + 1)) % mod
            b = (b + ra + rb) % mod
    return a, b
 
 
n = int(input())
tree = defaultdict(list)
for _ in range(n - 1):
    u, v = map(int, input().strip().split())
    tree[u].append(v)
    tree[v].append(u)
print((sum(attack(0, tree, [False] * n)) + 1) % mod)
