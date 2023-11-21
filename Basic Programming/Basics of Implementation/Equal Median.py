t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().strip().split()))
    b = sorted(map(int, input().strip().split()))
    mid = n // 2
    if a[mid] == b[mid]:
        print(0)
        continue
    c = sorted(a + b)
    median = c[n - 1]
    if c[n] != median:
        print(-1)
        continue
    if median not in b:
        a, b = b, a
    lta = sum(1 for i in a if i < median)
    if median not in a:
        if lta <= mid:
            print(mid - lta + 1)
            continue
        print(lta - mid)
        continue
    ltb = sum(1 for i in b if i < median)
    eqa = a.count(median)
    eqb = b.count(median)
    gta = n - lta - eqa
    gtb = n - ltb - eqb
    print(max(0, lta - mid, gta - mid, ltb - mid, gtb - mid))
