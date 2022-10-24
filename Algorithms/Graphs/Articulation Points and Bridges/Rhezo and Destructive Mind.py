from collections import defaultdict
 
n, m = map(int, input().strip().split())
edges = defaultdict(list)
for _ in range(m):
    a, b = map(int, input().strip().split())
    edges[a].append(b)
    edges[b].append(a)
time = 1
 
 
def dfs(node, parent, adj, disc_list, low_list, counter):
    global time
    disc_list[node] = time
    low_list[node] = time
    time += 1
    count = 0
    for next_node in adj[node]:
        if next_node != parent:
            if disc_list[next_node] == -1:
                count += 1
                dfs(next_node, node, adj, disc_list, low_list, counter)
                low_list[node] = min(low_list[node], low_list[next_node])
                if not parent:
                    if count > 1:
                        counter[node] = count
                elif low_list[next_node] >= disc_list[node]:
                    counter[node] = 0
            else:
                low_list[node] = min(low_list[node], disc_list[next_node])
    if node in counter:
        counter[node] = len(adj[node])
 
 
disc = [-1] * (n + 1)
low = [-1] * (n + 1)
res = {}
for a in edges:
    dfs(a, None, edges, disc, low, res)
q = int(input())
for _ in range(q):
    x = int(input())
    if x in res:
        print('Satisfied', res[x])
    else:
        print('Not Satisfied')
