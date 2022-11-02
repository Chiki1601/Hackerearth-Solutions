from collections import defaultdict
 
 
def invite(node, adjacency):
    visited = {node}
    stack = [node]
    count = 0
    while stack:
        aux = stack.pop()
        count += 1
        for vertex in adjacency[aux]:
            if vertex not in visited:
                visited.add(vertex)
                stack.append(vertex)
    return count
 
 
n, d = map(int, input().strip().split())
friends = defaultdict(set)
for _ in range(d):
    a, b = map(int, input().strip().split())
    friends[a].add(b)
ans = float('inf')
for i in range(1, n + 1):
    ans = min(ans, invite(i, friends))
print(ans)
