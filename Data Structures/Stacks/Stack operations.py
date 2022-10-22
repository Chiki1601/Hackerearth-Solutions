n, k = map(int, input().strip().split())
a = list(map(int, input().strip().split()))
if n == 1 and k % 2 == 1:
    print(-1)
elif k <= n:
    print(max(a[:k - 1] + a[k:k + 1]))
else:
    print(max(a))
