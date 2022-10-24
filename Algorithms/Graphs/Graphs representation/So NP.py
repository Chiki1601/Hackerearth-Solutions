n, m, k = map(int, input().strip().split())
if n - m > k or (n, m, k) == (4, 3, 1):
    print(-1)
else:
    print(m + k - n)
