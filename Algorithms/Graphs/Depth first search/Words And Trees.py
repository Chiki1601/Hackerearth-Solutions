from collections import defaultdict
 
 
def adding(node, adjacency, seen, mapping):
    seen[node - 1] = True
    for vertex in adjacency[node]:
        if not seen[vertex - 1]:
            adding(vertex, adjacency, seen, mapping)
            mapping[node] += mapping[vertex]
 
 
n, q = map(int, input().strip().split())
letters = input().strip().split()
edges = defaultdict(list)
for _ in range(n - 1):
    u, v = map(int, input().strip().split())
    edges[u].append(v)
    edges[v].append(u)
visited = [False] * n
subtrees = {i + 1: letters[i] for i in range(n)}
adding(1, edges, visited, subtrees)
for _ in range(q):
    x, s = input().strip().split()
    subtree = list(subtrees[int(x)])
    count = 0
    for c in s:
        if c in subtree:
            subtree.remove(c)
        else:
            count += 1
    print(count)
