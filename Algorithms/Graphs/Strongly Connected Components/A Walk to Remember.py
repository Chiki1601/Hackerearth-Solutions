# Write your code here
import sys
import threading
from collections import defaultdict
 
idx = -1
 
 
def tarjan(node, adj, size, scc, disc, low, visited, stack):
    global idx
    idx += 1
    disc[node] = idx
    low[node] = idx
    visited[node] = True
    stack.append(node)
    for neighbor in adj[node]:
        if disc[neighbor] == -1:
            low[node] = min(low[node], tarjan(neighbor, adj, size, scc, disc, low, visited, stack))
        elif visited[neighbor]:
            low[node] = min(low[node], disc[neighbor])
    if low[node] == disc[node]:
        substack = []
        while stack[-1] != node:
            visited[stack[-1]] = False
            substack.append(stack.pop())
        visited[stack[-1]] = False
        substack.append(stack.pop())
        scc.append(substack)
    return low[node]
 
 
def solve():
    n, m = map(int, sys.stdin.readline().strip().split())
    graph = defaultdict(list)
    for _ in range(m):
        u, v = map(lambda x: int(x) - 1, sys.stdin.readline().strip().split())
        graph[u].append(v)
    disc_list = [-1] * n
    low_list = [-1] * n
    seen = [False] * n
    node_list = []
    res = []
    for i in range(n):
        if disc_list[i] == -1:
            tarjan(i, graph, n, res, disc_list, low_list, seen, node_list)
    ans = [0] * n
    for i in res:
        if len(i) > 1:
            for j in i:
                ans[j] = 1
    print(*ans)
 
 
sys.setrecursionlimit(100000)
threading.stack_size(10 ** 8)
t = threading.Thread(target=solve)
t.start()
t.join()
