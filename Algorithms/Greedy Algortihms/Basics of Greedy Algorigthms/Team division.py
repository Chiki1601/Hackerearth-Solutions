t = int(input())
for _ in range(t):
    n = int(input())
    x = sorted(map(int, input().strip().split()))
    print(x[n // 2] - x[n // 2 - 1] + 1)
