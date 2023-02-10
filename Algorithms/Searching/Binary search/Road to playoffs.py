t = int(input())
for _ in range(t):
    n, m, k, b = map(int, input().strip().split())
    x = sorted(map(int, input().strip().split()), reverse=True)
    left = b - 1
    right = n - 1
    while left < right:
        mid = right - (right - left) // 2  # don't use (right + left) // 2
        if x[b - 1] > x[mid] + m:
            right = mid - 1
        else:
            cur = 0
            for i in range(b - 1, mid):
                cur += x[mid] + m - x[i]
            if cur < m * (k - (b - 1) - (n - mid)):
                right = mid - 1
            else:
                left = mid
    print(left + 1)
