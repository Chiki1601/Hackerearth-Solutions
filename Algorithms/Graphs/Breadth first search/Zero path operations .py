t = int(input())
for _ in range(t):
    n = int(input())
    degree = [0] * n
    for i in range(n - 1):
        u, v = map(int, input().strip().split())
        degree[u - 1] += 1
        degree[v - 1] += 1
    w = list(map(int, input().strip().split()))
    res = 0
    for i in range(n):
        if degree[i] > 1 and w[i] != 0:
            res += 1
    print(res)
