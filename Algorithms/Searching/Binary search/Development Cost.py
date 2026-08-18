def solve(R, C, M, K, grid, missions):
    # Convert mission coordinates from 1-based to 0-based
    missions = [(a - 1, b - 1, c - 1, d - 1)
                for a, b, c, d in missions]

    values = sorted(set(value for row in grid for value in row))

    def can(limit):
        # -1 means not visited
        component = [[-1] * C for _ in range(R)]

        comp_id = 0

        for i in range(R):
            for j in range(C):
                if component[i][j] != -1:
                    continue

                if grid[i][j] > limit:
                    continue

                # BFS
                stack = [(i, j)]
                component[i][j] = comp_id

                while stack:
                    x, y = stack.pop()

                    if x > 0 and component[x - 1][y] == -1:
                        if grid[x - 1][y] <= limit:
                            component[x - 1][y] = comp_id
                            stack.append((x - 1, y))

                    if x + 1 < R and component[x + 1][y] == -1:
                        if grid[x + 1][y] <= limit:
                            component[x + 1][y] = comp_id
                            stack.append((x + 1, y))

                    if y > 0 and component[x][y - 1] == -1:
                        if grid[x][y - 1] <= limit:
                            component[x][y - 1] = comp_id
                            stack.append((x, y - 1))

                    if y + 1 < C and component[x][y + 1] == -1:
                        if grid[x][y + 1] <= limit:
                            component[x][y + 1] = comp_id
                            stack.append((x, y + 1))

                comp_id += 1

        # Count missions that can be completed
        count = 0

        for x1, y1, x2, y2 in missions:
            if (component[x1][y1] != -1 and
                    component[x1][y1] == component[x2][y2]):
                count += 1

                if count >= K:
                    return True

        return False

    # Binary search for minimum possible development cost
    left = 0
    right = len(values) - 1
    answer = values[-1]

    while left <= right:
        mid = (left + right) // 2
        limit = values[mid]

        if can(limit):
            answer = limit
            right = mid - 1
        else:
            left = mid + 1

    return answer


# Input
R, C, M, K = map(int, input().split())

grid = []
for _ in range(R):
    grid.append(list(map(int, input().split())))

missions = []
for _ in range(M):
    missions.append(tuple(map(int, input().split())))

print(solve(R, C, M, K, grid, missions))
