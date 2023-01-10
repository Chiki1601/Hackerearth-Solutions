from collections import Counter

t = int(input())
for _ in range(t):
    m, n = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))
    c = Counter(a + b)
    f = sorted(c.keys())
    ans = 0
    for i in f:
        if c[i] >= m:
            ans += 1
    d = 1
    while True:
        if f[0] + (m - 1) * d > f[-1]:
            break
        dp = {}
        for i in range(len(f) - 1, -1, -1):
            x = f[i] + d
            if x in dp:
                dp[f[i]] = dp[x] + 1
                if dp[f[i]] >= m:
                    ans += 2
            else:
                dp[f[i]] = 1
        d += 1
    print(ans)
