# Write your code here
from collections import defaultdict, deque
 
 
def find_height(height, point, heights, adjacency, seen):
    queue = deque([point])
    seen[point] = True
    result = float('-inf')
    while queue:
        cur = queue.popleft()
        for neighbor in adjacency[cur]:
            if not seen[neighbor]:
                seen[neighbor] = True
                queue.append(neighbor)
                result = max(result, heights[neighbor] - height)
    return result
 
 
t = int(input())
for _ in range(t):
    n, m = map(int, input().strip().split())
    h = list(map(int, input().strip().split()))
    lanes = defaultdict(list)
    for _ in range(m):
        a, b = map(lambda x: int(x) - 1, input().strip().split())
        lanes[a].append(b)
    visited = [False] * n
    points = sorted((v, i) for i, v in enumerate(h))
    ans = float('-inf')
    for v, i in points:
        if not visited[i]:
            res = find_height(v, i, h, lanes, visited)
            ans = max(ans, res)
    print(ans)
