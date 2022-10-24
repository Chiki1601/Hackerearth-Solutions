# Write your code here
from collections import defaultdict, deque
 
 
def dance(adjacency, lvl):
    q = deque([(0, 0)])
    visited = {0: 0}
    while q:
        u, w = q.popleft()
        for v in adjacency[u]:
            if v not in visited:
                visited[v] = 0
                lvl[v] = w + 1
                q.append((v, w + 1))
 
 
a, b = map(int, input().strip().split())
couples = defaultdict(list)
luckiness = {}
for _ in range(b):
    x, y = map(int, input().strip().split())
    couples[x].append(y)
    couples[y].append(x)
dance(couples, luckiness)
for i in range(1, a):
    if i in luckiness:
        print(luckiness[i])
    else:
        print(-1)
