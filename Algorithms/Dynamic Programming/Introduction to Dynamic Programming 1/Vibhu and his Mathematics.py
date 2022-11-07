t = int(input())
q = []
for _ in range(t):
    n = int(input())
    q.append(n)
ln = max(q)
dp = [1] * (ln + 1)
for i in range(2, ln + 1):
    dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2]) % 1000000007
for n in q:
    print(dp[n])
