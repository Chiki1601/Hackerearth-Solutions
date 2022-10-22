n, k = map(int, input().strip().split())
a = [[0] * (n + 1)]
for _ in range(n):
    a.append([0] + list(map(int, input().strip().split())))
for i in range(1, n + 1):
    for j in range(1, n + 1):
        a[i][j] += a[i][j - 1]
    for j in range(1, n + 1):
        a[i][j] += a[i - 1][j]
low, high = 1, n + 1
while low < high:
    mid = (low + high) // 2
    for i in range(mid, n + 1):
        for j in range(mid, n + 1):
            if a[i][j] - a[i - mid][j] - a[i][j - mid] + a[i - mid][j - mid] >= k:
                break
        else:
            continue
        break
    else:
        low = mid + 1
        continue
    high = mid
if low > n:
    print('NO')
else:
    print('YES')
    for i in range(low, n + 1):
        for j in range(low, n + 1):
            if a[i][j] - a[i - low][j] - a[i][j - low] + a[i - low][j - low] >= k:
                print(i - low + 1, j - low + 1, i, j)
                break
        else:
            continue
        break
