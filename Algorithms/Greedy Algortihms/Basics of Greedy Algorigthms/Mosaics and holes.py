# Write your code here
n, m, k = map(int, input().strip().split())
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().strip().split())))
ps = [[0] * (m + 2) for _ in range(n + 2)]
ans = 0
for i in range(1, n + 1):
    for j in range(1, m + 1):
        ps[i][j] = ps[i - 1][j] ^ ps[i][j - 1] ^ ps[i - 1][j - 1] ^ ps[i][j]
        if ps[i][j] == matrix[i - 1][j - 1]:
            if i + k > n + 1 or j + k > m + 1:
                ans = -1
                break
            ps[i][j] ^= 1
            ps[i + k][j] ^= 1
            ps[i][j + k] ^= 1
            ps[i + k][j + k] ^= 1
            ans += 1
    if ans == -1:
        break
print(ans)
