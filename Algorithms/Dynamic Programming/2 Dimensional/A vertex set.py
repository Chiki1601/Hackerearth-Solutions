from collections import defaultdict
def dfs(tree, val, node=0, parent=-1):
    ans = [0, 0, val[node]]
    for next_node in tree[node]:
        if next_node != parent:
            res = dfs(tree, val, next_node, node)
            ans[2] = max(ans[2], res[2])
            ans[0] += res[1]
            ans[1] += res[0]
    ans[0] = max(ans[0] + ans[2], ans[1])
    return ans
 
 
t = int(input())
for _ in range(t):
    n = int(input())
    edges = defaultdict(list)
    for _ in range(n - 1):
        u, v = map(lambda x: int(x) - 1, input().split())
        edges[u].append(v)
        edges[v].append(u)
    values = list(map(int, input().strip().split()))
    print(dfs(edges, values)[0])
