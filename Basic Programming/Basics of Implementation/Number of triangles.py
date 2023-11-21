t = int(input())
for _ in range(t):
    n, b1, b2 = map(int, input().strip().split())
    x = abs(b1 - b2) - 1
    y = n - x - 2
    ans = 0
    if x >= 2:
        ans += (x - 1) * y
        if x >= 3:
            ans += x - 2
            ans += (x - 2) * (x - 3)
    if y >= 2:
        ans += (y - 1) * x
        ans += y - 2
        ans += (y - 2) * (y - 3)
    print(ans)
