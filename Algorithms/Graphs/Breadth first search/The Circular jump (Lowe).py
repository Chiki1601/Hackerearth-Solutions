# Write your code here
from collections import deque
 
 
def count_jumps(nums, chair_x, chair_y, n_chair):
    visited = [False] * n_chair
    queue = deque([(chair_x, 0)])
    while queue:
        chair_x, lvl = queue.popleft()
        if chair_x == chair_y:
            return lvl
        for chair in (chair_x - nums[chair_x]) % n_chair, (chair_x + nums[chair_x]) % n_chair:
            if not visited[chair]:
                visited[chair] = True
                queue.append((chair, lvl + 1))
    return -1
 
 
t = int(input())
for _ in range(t):
    n, x, y = map(int, input().strip().split())
    x -= 1
    y -= 1
    jumps = list(map(int, input().strip().split()))
    print(count_jumps(jumps, x, y, n))
