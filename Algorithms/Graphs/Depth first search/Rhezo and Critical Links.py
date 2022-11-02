# Write your code here
# import resource  # uncomment this when submitting
import sys
from collections import defaultdict, deque
 
# resource.setrlimit(resource.RLIMIT_STACK, (2 ** 25, -1))  # uncomment this when submitting
sys.setrecursionlimit(100000)
 
 
def check(x, level, adjacency, seen, ranks, counts):
    seen[x] = True
    ranks[x] = level
    counts[level] += 1
    stack = deque([x])
    while stack:
        u = stack.pop()
        for v in adjacency[u]:
            if not seen[v]:
                seen[v] = True
                ranks[v] = level
                counts[level] += 1
                stack.append(v)
 
 
def tarjan(u, parent, adjacency, seen, ranks, counts, size, low, num, limit):
    seen[u] = True
    size[u] = 1
    global count
    count += 1
    low[u] = num[u] = count
    for v in adjacency[u]:
        if v != parent:
            if seen[v]:
                low[u] = min(low[u], num[v])
            else:
                tarjan(v, u, adjacency, seen, ranks, counts, size, low, num, limit)
                low[u] = min(low[u], low[v])
                size[u] += size[v]
                if low[v] > num[u] and abs(size[v] - (counts[ranks[u]] - size[v])) < limit:
                    global ans
                    ans += 1
 
 
n, m, p = map(int, input().strip().split())
edges = defaultdict(list)
for _ in range(m):
    a, b = map(lambda x: int(x) - 1, input().strip().split())
    edges[a].append(b)
    edges[b].append(a)
visited = [False] * n
lvl = -1
levels = [0] * n
counter = [0] * n
for i in range(n):
    if not visited[i]:
        lvl += 1
        check(i, lvl, edges, visited, levels, counter)
visited = [False] * n
size_arr = [0] * n
low_arr = [0] * n
num_arr = [0] * n
count = 0
ans = 0
for i in range(n):
    if not visited[i]:
        tarjan(i, -1, edges, visited, levels, counter, size_arr, low_arr, num_arr, p)
print(ans)
