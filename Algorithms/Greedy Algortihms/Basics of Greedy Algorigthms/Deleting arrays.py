t = int(input())
for _ in range(t):
    n, k = map(int, input().strip().split())
    print((n + 2 * k) // (2 * k + 1))
