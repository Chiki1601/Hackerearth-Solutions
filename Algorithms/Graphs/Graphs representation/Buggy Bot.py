# Write your code here
from collections import defaultdict
 
n, m, k = map(int, input().strip().split())
adjacency = defaultdict(list)
for _ in range(m):
    a, b = map(int, input().strip().split())
    adjacency[a].append(b)
final = [False] * (n + 1)
for node in adjacency[1]:
    final[node] = True
buggy = 1
neighboring_nodes = defaultdict(set)
for _ in range(k):
    x, y = map(int, input().strip().split())
    if final[x]:
        final[x] = False
        for pa in neighboring_nodes[x]:
            adjacency[pa].append(x)
        neighboring_nodes[x] = set()
        final[y] = True
    if buggy == x:
        buggy = y
    for node in adjacency[buggy]:
        final[node] = True
        neighboring_nodes[node].add(buggy)
    adjacency[buggy] = []
final[buggy] = True
print(sum(final))
print(' '.join(str(i) for i in range(n + 1) if final[i] is True))
