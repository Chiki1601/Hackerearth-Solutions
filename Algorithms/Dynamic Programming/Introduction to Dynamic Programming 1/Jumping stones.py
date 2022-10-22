n, k = map(int, input().strip().split())
dp = [0] * n
suf = [0] * (n + 1)
dp[n - 1] = 1
suf[n - 1] = 1
mod = 1000000007
for i in range(n - 2, -1, -1):
    dp[i] = (suf[i + 1] - suf[min(n, i + 1 + k)]) % mod
    suf[i] = (dp[i] + suf[i + 1]) % mod
print(dp[0])
