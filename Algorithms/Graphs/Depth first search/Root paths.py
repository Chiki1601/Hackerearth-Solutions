# Write your code here
from collections import defaultdict, deque
 
n, q, t = map(int, input().strip().split())
graph = defaultdict(list)
last_ans = 0
visited = {1}
for _ in range(q):
    query = list(map(int, input().strip().split()))
    if query[0] == 1:
        a, b = query[1:]
        u = (a ^ (t * last_ans)) % n + 1
        v = (b ^ (t * last_ans)) % n + 1
        if v not in visited:
            graph[u].append(v)
        if u in visited and v not in visited:
            queue = deque([v])
            visited.add(v)
            while queue:
                x = queue.pop()
                for y in graph[x]:
                    if y not in visited:
                        queue.append(y)
                        visited.add(y)
                graph[x] = []
    elif query[0] == 2:
        a = query[-1]
        x = (a ^ (t * last_ans)) % n + 1
        last_ans = x if x in visited else 0
        print(last_ans)
