n, x = map(int, input().strip().split())
arr = sorted(map(int, input().strip().split()))
res = arr[-1] - arr[0]
for i in range(n - 1):
    high = max(arr[i] + x, arr[-1] - x)
    low = min(arr[0] + x, arr[i + 1] - x)
    res = min(res, high - low)
print(res)
