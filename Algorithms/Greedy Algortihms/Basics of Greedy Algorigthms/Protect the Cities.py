t = int(input())
for _ in range(t):
    n = int(input())
    xs = []
    ys = []
    for _ in range(n):
        x, y = map(int, input().strip().split())
        xs.append(x)
        ys.append(y)
    print(max(max(xs) - min(xs), max(ys) - min(ys)) ** 2)
