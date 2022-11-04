# Write your code here
n = int(input())
s = input().strip()
s = s.replace('=', '')
mod = 1000000007
dp = [1] * (n + 1)
dp[0] = 0
for i in range(len(s)):
    tmp = [0] * (n + 1)
    if s[i] == '<':
        total = 0
        for j in range(2, n + 1):
            total += dp[j - 1]
            total %= mod
            tmp[j] = total
    elif s[i] == '>':
        total = 0
        for j in range(n - 1, 0, -1):
            total += dp[j + 1]
            total %= mod
            tmp[j] = total
    dp = tmp.copy()
print(sum(dp) % mod)
