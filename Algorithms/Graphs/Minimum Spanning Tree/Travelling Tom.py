from collections import defaultdict, deque
 
 
def count_cities(adjacency, length):
    count = 0
    start = 1
    queue = deque([start])
    visited = [False] * length
    visited[start - 1] = True
    while queue:
        x = queue.pop()
        count += 1
        for y, _ in adjacency[x]:
            if not visited[y - 1]:
                visited[y - 1] = True
                queue.append(y)
    return count
 
 
def compute(adjacency, length, tot):
    count = 0
    start = 1
    queue = deque([start])
    visited = [False] * length
    visited[start - 1] = True
    while queue:
        x = queue.pop()
        count += 1
        for y, z in adjacency[x]:
            if not visited[y - 1] and z & tot == z:
                visited[y - 1] = True
                queue.append(y)
    return count
 
 
n, m, k = map(int, input().strip().split())
tokens = list(map(int, input().strip().split()))
roads = defaultdict(list)
for i in range(m):
    u, v, l, *required_tokens = list(map(int, input().strip().split()))
    cost = 0
    for c in required_tokens:
        cost |= 1 << c - 1
    roads[u].append((v, cost))
    roads[v].append((u, cost))
size = count_cities(roads, n)
if size != n:
    print(-1)
else:
    ans = 0
    cost = (1 << k) - 1
    total = 0
    for i in range(k - 1, -1, -1):
        curr_cost = cost ^ 1 << i
        size = compute(roads, n, curr_cost)
        if size != n:
            total += tokens[i]
        else:
            cost = curr_cost
    print(total)
