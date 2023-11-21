t = int(input())
for _ in range(t):
    n, m, k = map(int, input().strip().split())
    boxs = sorted(map(int, input().strip().split()), reverse=True)
    balls = sorted(map(int, input().strip().split()), reverse=True)
    i = j = ans = 0
    while i < m and j < n:
        if boxs[j] <= balls[i] <= (boxs[j] + k):
            i += 1
            j += 1
            ans += 1
        elif balls[i] < boxs[j]:
            j += 1
        else:
            i += 1
    print(ans)
