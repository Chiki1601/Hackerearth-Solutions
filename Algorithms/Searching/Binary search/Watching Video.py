# Write your code here
n, d = map(int, input().strip().split())
x = list(map(int, input().strip().split()))
dp = [0] * len(x)
cache = 0
for i in range(n):
    cache += x[i]
    if cache >= d:
        dp[i], cache = divmod(cache, d)
play = cache = 0
for i in range(n):
    if dp[i]:
        play = max(play, i - cache)
    cache += dp[i]
print(play + 1)
