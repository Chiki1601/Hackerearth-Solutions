t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    total = sum(a)
    accumulation = 0
    if a[0] > total / 2:
        print(-1)
    else:
        i = 0
        while accumulation < total - accumulation:
            accumulation += a[i]
            i += 1
        if accumulation == total - accumulation:
            print(0)
        else:
            accumulation -= a[i - 1]
            print(total - 2 * accumulation)
