t = int(input())
for _ in range(t):
    x = int(input())
    if x // 4 < 3:
        print(0, 0)
    else:
        d = (1 + 8 * (x // 4)) ** .5
        a = 2 * (int((d - 1) // 4) - 1) + 1
        b = 2 * (int((d + 1) // 4) - 1) + 1
        if a >= b:
            print(a, a + 1)
        else:
            print(b, b - 1)
