r, g, b = map(int, input().strip().split())
m = min(r, g, b)
r -= m
g -= m
b -= m
print((r + g + b + 1) // 2 + m)
