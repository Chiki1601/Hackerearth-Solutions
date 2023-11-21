t = int(input())
for _ in range(t):
    n, m = map(int, input().strip().split())
    s = 0
    while n > 0:
        s += ((n + 1) // 2) ** 2
        n //= 2
    print(s % m)
