t = int(input())
for _ in range(t):
    n = int(input())
    a = [0] + list(map(int, input().strip().split()))
    for i in range(1, n + 1):
        if a[i] > i:
            j = a.index(i)
            a[i], a[j] = a[j], a[i]
            break
    else:
        a[-1], a[-2] = a[-2], a[-1]
    print(*a[1:])
