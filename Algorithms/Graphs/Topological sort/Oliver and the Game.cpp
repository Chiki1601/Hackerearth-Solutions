# Write your code here
from collections import defaultdict, deque
from sys import stdin
 
v = int(stdin.readline())
road = defaultdict(list)
for _ in range(v - 1):
    a, b = map(lambda x: int(x) - 1, stdin.readline().strip().split())
    road[a].append(b)
    road[b].append(a)
paths = [[False, 0, 0] for _ in range(v)]  # visited, start, end
stack = deque([0])
i = 0
while stack:
    u = stack[-1]
    if paths[u][0]:
        paths[u][2] = i
        stack.pop()
    else:
        paths[u][0] = True
        paths[u][1] = i
        for v in road[u]:
            if not paths[v][0]:
                stack.append(v)
    i += 1
q = int(stdin.readline())
for _ in range(q):
    t, x, y = map(int, stdin.readline().strip().split())
    x -= 1
    y -= 1
    _, start1, end1 = paths[x]
    _, start2, end2 = paths[y]
    if t:
        if start2 <= start1 and end2 >= end1:
            print('YES')
            continue
    else:
        if start2 >= start1 and end2 <= end1:
            print('YES')
            continue
    print('NO')
