t = int(input())
for _ in range(t):
    n, x, y = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    if n <= x or n <= y:
        print(n)
    else:
        tot = ln = mx = 0
        for i in range(n):
            tot += a[i]
            if a[i] < x and tot <= x:
                ln += 1
            elif a[i] < x:
                ln = 1
                tot = a[i]
            else:
                tot = ln = 0
            mx = max(mx, ln)
        print(mx + y)
