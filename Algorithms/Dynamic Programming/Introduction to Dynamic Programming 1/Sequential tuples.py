t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print(1)
    elif n == 2:
        print(4)
    elif n == 3:
        print(10)
    else:
        print((n - 2) * 9)
