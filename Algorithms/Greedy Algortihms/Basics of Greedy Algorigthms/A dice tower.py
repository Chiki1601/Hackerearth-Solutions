t = int(input())
for _ in range(t):
    n = int(input())
    if n >= 28 and 2 <= n % 14 <= 12:
        print(n // 14)
    elif n == 21:
        print(1)
    else:
        print(-1)
