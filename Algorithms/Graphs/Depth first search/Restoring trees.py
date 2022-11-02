n = int(input())
start = list(map(int, input().strip().split()))
finish = list(map(int, input().strip().split()))
vertexes = [0] * n
for i, v in enumerate(start):
    vertexes[v] = i
parents = [-1] * n
parent = vertexes[0]
for i in range(1, n):
    cur = vertexes[i]
    if finish[cur] - i > 1:
        parents[cur] = parent
        parent = cur
    else:
        parents[cur] = parent
        while finish[cur] == finish[parents[cur]]:
            cur = parents[cur]
            parent = parents[cur]
            if parent == vertexes[0]:
                break
for i in range(n):
    parents[i] += 1
print(*parents)
