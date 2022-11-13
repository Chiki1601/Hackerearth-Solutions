t = int(input())
for _ in range(t):
    n = int(input())
    x = list(map(int, input().strip().split()))
    y = list(map(int, input().strip().split()))
    a = sorted(2 * x[i] + y[i] for i in range(n))
    ans = 0
    total = sum(x)
    while total >= 0:
        total -= a.pop()
        ans += 1
    print(ans)
