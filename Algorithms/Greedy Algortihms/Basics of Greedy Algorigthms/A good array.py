t = int(input())
for _ in range(t):
    n, x, y = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    b = a[::2]
    c = a[1::2]
    print(min(b.count(0) * x + c.count(1) * y, b.count(1) * y + c.count(0) * x))
