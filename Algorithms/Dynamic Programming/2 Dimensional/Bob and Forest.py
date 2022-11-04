# Write your code here
n, m = map(int, input().strip().split())
matrix = [[0] * m for _ in range(n)]
for i in range(n):
    line = input().strip()
    for j in range(m):
        if line[j] == '*':
            matrix[i][j] = 1
dp = [[0] * m for _ in range(n)]
size = min(n, m)
ans = [0] * (size + 1)
for i in range(n):
    for j in range(m):
        if i == 0 or j == 0:
            x = dp[i][j] = matrix[i][j]
            ans[x] += x == 1
        else:
            if matrix[i][j] != 0:
                x = dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1
                ans[x] += 1
for i in range(size - 1, 0, -1):
    ans[i] += ans[i + 1]
for i in range(1, size + 1):
    ans[i] += ans[i - 1]
q = int(input())
for _ in range(q):
    k = int(input())
    k = min(k, size)
    print(ans[k])
