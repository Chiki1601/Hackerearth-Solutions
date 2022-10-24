t = int(input())
for _ in range(t):
    n, a, b = map(int, input().strip().split())
    x = round(n * b / (a + b))
    y = n - x
    print(a * x * x + b * y * y)
