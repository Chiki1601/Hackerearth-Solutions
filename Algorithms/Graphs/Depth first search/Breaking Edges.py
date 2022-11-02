# Write your code here
from collections import deque, defaultdict
 
SIZE = 20  # v < 1048575, 2^20 = 1048576
 
 
def solve():
    n = int(input())
    v = list(map(int, input().strip().split()))
    edges = defaultdict(list)
    for _ in range(n - 1):
        a, b = map(lambda x: int(x) - 1, input().strip().split())
        edges[a].append(b)
        edges[b].append(a)
    counts = [[0] * SIZE for _ in range(n)]
    for i in range(n):
        for j in range(SIZE):
            if 1 << j & v[i]:  # 1 << x is 2^x,
                counts[i][j] += 1
    visited = [False] * n
    visited[0] = True
    pointers = [0] * n
    children = defaultdict(list)
    stack = deque([0])
    while stack:
        u = stack[-1]
        for i in range(pointers[u], len(edges[u])):
            v = edges[u][i]
            pointers[u] += 1
            if not visited[v]:
                visited[v] = True
                stack.append(v)
                children[u].append(v)
                break
        else:
            for v in children[u]:
                for w in range(SIZE):
                    counts[u][w] += counts[v][w]
            stack.pop()
    res = 0
    for i in range(1, n):
        for j in range(SIZE):
            if (not counts[i][j] and counts[0][j] > counts[i][j]) or (0 < counts[i][j] == counts[0][j]):
                break
        else:
            res += 1
    print(res)
 
 
solve()
