s = input()
points = [(0, 0)]
x = y = 0
for move in s:
    if move == 'L':
        y -= 1
    elif move == 'R':
        y += 1
    elif move == 'U':
        x -= 1
    else:
        x += 1
    points.append((x, y))
print(len(points) - len(set(points)))
