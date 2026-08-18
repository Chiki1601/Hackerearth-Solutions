n = int(input())
p = list(map(int, input().split()))

# Current beauty
beauty = 0

for i in range(n):
    beauty += abs(p[i] - (i + 1))

best_gain = 0

# Try all 4 combinations of signs.
for s in (1, -1):
    for t in (1, -1):

        # Best two values of X and Y.
        # Each entry is (value, index)
        best_x = [(-10**30, -1), (-10**30, -1)]
        best_y = [(-10**30, -1), (-10**30, -1)]

        for i in range(1, n + 1):
            a = p[i - 1]
            old = abs(a - i)

            # Derived from:
            # |p[j] - i| + |p[i] - j|
            x = t * a - s * i - old
            y = s * a - t * i - old

            # Keep top 2 X values
            if x > best_x[0][0]:
                best_x[1] = best_x[0]
                best_x[0] = (x, i)
            elif x > best_x[1][0]:
                best_x[1] = (x, i)

            # Keep top 2 Y values
            if y > best_y[0][0]:
                best_y[1] = best_y[0]
                best_y[0] = (y, i)
            elif y > best_y[1][0]:
                best_y[1] = (y, i)

        # Choose different indices
        for x_value, x_index in best_x:
            for y_value, y_index in best_y:
                if x_index != y_index:
                    best_gain = max(
                        best_gain,
                        x_value + y_value
                    )

print(beauty + best_gain)
