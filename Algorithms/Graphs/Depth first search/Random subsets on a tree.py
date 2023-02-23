from bisect import bisect_left, insort_left
from collections import deque
from sys import stdin

MOD = 1000000007

n = int(stdin.readline())
edges = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, stdin.readline().strip().split())
    edges[u].append(v)
    edges[v].append(u)
val = [0] + list(map(int, stdin.readline().strip().split()))
val_sorted = []
visited = [False] * (n + 1)
counts = [0] * (n + 1)
dp = [[] for _ in range(n + 1)]
stack = deque([1])
visited[1] = True
while stack:
    curr = stack[-1]
    if not counts[curr]:
        idx = bisect_left(val_sorted, val[curr])
        insort_left(val_sorted, val[curr])
        dp[curr].append(idx)
    for i in range(counts[curr], len(edges[curr])):
        j = edges[curr][i]
        counts[curr] += 1
        if not visited[j]:
            idx = bisect_left(val_sorted, val[curr])
            dp[curr].append(idx)
            stack.append(j)
            visited[j] = True
            break
    else:
        visited[curr] = True
        idx = bisect_left(val_sorted, val[curr])
        dp[curr].append(idx)
        stack.pop()
ans = pow(2, n, MOD) - 1
for i in range(1, n + 1):
    if len(dp[i]) > 2:
        x = 0
        temp = 0
        for j in range(1, len(dp[i])):
            if dp[i][j] - dp[i][j - 1] > 0:
                x += dp[i][j] - dp[i][j - 1]
                temp -= (pow(2, dp[i][j] - dp[i][j - 1], MOD) - 1)
                temp %= MOD
        temp += (pow(2, x, MOD) - 1)
        temp %= MOD
        ans += temp * (i - 1)
        ans %= MOD
print((ans * pow(pow(2, n, MOD), MOD - 2, MOD)) % MOD)
