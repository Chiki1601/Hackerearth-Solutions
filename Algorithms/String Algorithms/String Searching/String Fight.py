t = int(input())
for _ in range(t):
    p, c = input().strip().split()
    p = int(p)
    a = [-1]
    b = input()
    for i, v in enumerate(b):
        if v == c:
            a.append(i)
    a.append(len(b))
    ans = 0
    for i in range(1, len(a) - p):
        x = a[i] - a[i - 1]
        y = a[i + p] - a[i + p - 1]
        ans += x * y
    print(ans)
