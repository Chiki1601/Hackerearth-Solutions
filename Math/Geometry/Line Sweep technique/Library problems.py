import math

n, r = map(int, input().split())

tables = [tuple(map(int, input().split())) for _ in range(n)]

# Sort the tables
tables.sort()

covered = [False] * n
lights = []

r2 = r * r  # Compare squared distances to avoid sqrt()

for i in range(n):
    if covered[i]:
        continue

    # Place a light at this table
    x, y = tables[i]
    lights.append((x, y))

    # Cover all tables within radius r
    for j in range(i, n):
        if covered[j]:
            continue

        x2, y2 = tables[j]

        distance2 = (x - x2) ** 2 + (y - y2) ** 2

        if distance2 <= r2:
            covered[j] = True

print(len(lights))

for x, y in lights:
    print(x, y)
    
