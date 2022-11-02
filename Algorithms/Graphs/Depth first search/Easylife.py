from collections import defaultdict
 
 
def count(start, adjacency, seen):
    stack = [start]
    seen[start] = True
    count_next = count_neighbour = 0
    while stack:
        vertex = stack.pop()
        seen[vertex] = True
        count_next += 1
        for neighbour in adjacency[vertex]:
            count_neighbour += 1
            if not seen[neighbour]:
                stack.append(neighbour)
    return count_neighbour // 2, count_next
 
 
n, m = map(int, input().strip().split())
graph = defaultdict(list)
for _ in range(m):
    u, v = map(int, input().strip().split())
    u -= 1
    v -= 1
    graph[u].append(v)
    graph[v].append(u)
density = 0
e = 0
v = 1
visited = [False] * n
for i in range(n):
    if not visited[i]:
        num_edge, num_ver = count(i, graph, visited)
        new_density = num_edge / num_ver
        if new_density > density:
            e = num_edge
            v = num_ver
            density = new_density
if density > 1:
    print('>1')
else:
    if e == v:
        e = v = 1
    print(f'{e}/{v}')
