t = int(input())
for _ in range(t):
    n = int(input())
    n += 1
    a = [int(i) for i in str(n)]
    b = []
    c = 0
    ln = len(a)
    for i in range(ln - 1, -1, -1):
        x = c + a[i]
        c = x // 10
        if x % 10 > 5:
            c += 1
            b.append(0)
        else:
            b.append(x % 10)
    if c != 0:
        b.append(c)
        ln += 1
    x = 0
    y = 0
    for i in range(ln - 1, -1, -1):
        y = 10 * y + b[i]
        if 10 * x + 3 >= y:
            x = 10 * x + 3
        else:
            x = 10 * x + 5
    print(int(x))
