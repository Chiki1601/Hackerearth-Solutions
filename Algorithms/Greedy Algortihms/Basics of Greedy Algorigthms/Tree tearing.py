import sys
from collections import defaultdict
 
sys.setrecursionlimit(100000)
 
k = int(input())
n = int(input())
if n == 1:
    print(0)
elif k == 1:
    vertices = input()
    print(n)
else:
    vertices = list(map(int, input().strip().split()))
    res = 0
 
 
    def dfs(adj, visited, i, k):
        global res
        des = 1
        visited[i] = True
        for j in adj[i]:
            if not visited[j]:
                des += dfs(adj, visited, j, k)
        if des >= k:
            res += 1
            des = 0
        return des
 
 
    graph = defaultdict(list)
    for i in range(2, len(vertices) + 2):
        v = vertices[i - 2]
        graph[i].append(v)
        graph[v].append(i)
    seen = [False] * (n + 1)
    dfs(graph, seen, 1, k)
    print(res)
