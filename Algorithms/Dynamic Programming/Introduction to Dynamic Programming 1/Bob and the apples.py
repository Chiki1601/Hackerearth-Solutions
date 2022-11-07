# Write your code here
t = int(input())
for _ in range(t):
    n, m = map(int, input().strip().split())
    apples = [tuple(map(int, input().strip().split())) for _ in range(n)]
    dp1 = [0] * (m + 1)
    dp2 = [0] * (m + 1)
    dp3 = [0] * (m + 1)
    for v, p in apples:
        tmp = dp1.copy()
        for i in range(m, p - 1, -1):
            dp1[i] = max(dp1[i], dp1[i - p] + v)
            dp3[i] = max(dp3[i], dp2[i - p] + v, dp3[i - p] + v)
        for i in range(m, p // 2 - 1, -1):
            dp2[i] = max(dp2[i], tmp[i - p // 2] + v)
    print(max(max(dp1), max(dp2), max(dp3)))
