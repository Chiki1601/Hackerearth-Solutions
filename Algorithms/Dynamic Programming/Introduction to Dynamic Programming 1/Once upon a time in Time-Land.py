t = int(input())
for _ in range(t):
    n, k = map(int, input().strip().split())
    a = list(map(int, input().split()))
    dp = [0 if i > k or a[i] < 0 else a[i] for i in range(n)]
    mx = -1
    for i in range(k + 1, n):
        mx = max(mx, dp[i - k - 1])
        dp[i] = a[i] + mx if a[i] > 0 else mx
    print(max(dp))
