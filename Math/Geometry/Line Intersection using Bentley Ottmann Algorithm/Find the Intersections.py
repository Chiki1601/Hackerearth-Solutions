n = int(input())

horizontal = []
vertical = []

for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())

    if y1 == y2:
        # Horizontal: x1 < x2
        horizontal.append((x1, x2, y1))
    else:
        # Vertical: y1 < y2
        vertical.append((x1, y1, y2))


intersections = []

for hx1, hx2, hy in horizontal:
    for vx, vy1, vy2 in vertical:

        # Check whether the vertical x lies inside horizontal
        # and horizontal y lies inside vertical.
        if hx1 <= vx <= hx2 and vy1 <= hy <= vy2:

            # Don't consider coincident endpoints.
            # H endpoint + V endpoint at the same point.
            horizontal_endpoint = (vx == hx1 or vx == hx2)
            vertical_endpoint = (hy == vy1 or hy == vy2)

            if horizontal_endpoint and vertical_endpoint:
                continue

            intersections.append((vx, hy))


# Remove duplicates if multiple segments intersect at the same point
intersections = sorted(set(intersections))

for x, y in intersections:
    print(x, y)
