t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    q = []
    turn = mx = 0
    for i in a:
        mx = max(mx, i)
        q.append(mx)
    mn = a[-1]
    for i in range(n - 2, -1, -1):
        if a[i] < mn:
            if q[i] < mn:
                turn += 1
            mn = a[i]
    if turn % 2:
        print('Jeel')
    else:
        print('Ashish')
