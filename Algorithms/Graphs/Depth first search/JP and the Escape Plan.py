from collections import deque
import sys

input = sys.stdin.buffer.readline

# Read N and M
n, m = map(int, input().split())

# Read grid
grid = [list(map(int, input().split())) for _ in range(n)]

# Starting position and maximum jump difference
dx, dy, J = map(int, input().split())

# Convert to 0-based indexing
dx -= 1
dy -= 1

# Directions: down, up, right, left
directions = [
    (1, 0),
    (-1, 0),
    (0, 1),
    (0, -1)
]

# Parent array for reconstructing the path
parent = [[None] * m for _ in range(n)]

# Visited array
visited = [[False] * m for _ in range(n)]

# BFS queue
q = deque()

q.append((dx, dy))
visited[dx][dy] = True

destination = None

while q:
    x, y = q.popleft()

    # If we reached boundary, escape is possible
    if x == 0 or x == n - 1 or y == 0 or y == m - 1:
        destination = (x, y)
        break

    current_height = grid[x][y]

    for move_x, move_y in directions:
        nx = x + move_x
        ny = y + move_y

        # Check bounds FIRST
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue

        # Already visited
        if visited[nx][ny]:
            continue

        next_height = grid[nx][ny]

        # Can move if:
        # 1. Same height
        # OR
        # 2. Destination is lower by at most J
        if next_height == current_height or (
            next_height < current_height
            and current_height - next_height <= J
        ):
            visited[nx][ny] = True
            parent[nx][ny] = (x, y)
            q.append((nx, ny))


# No boundary reachable
if destination is None:
    print("NO")
    sys.exit(0)

# Reconstruct path
path = []

cur = destination

while cur is not None:
    path.append(cur)
    cur = parent[cur[0]][cur[1]]

# Reverse path: starting point -> destination
path.reverse()

# Output
print("YES")
print(len(path))

for x, y in path:
    print(x + 1, y + 1)
