t = int(input())
for _ in range(t):
    n, k = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))
    print(sum(a) + sum(sorted(j - i for i, j in zip(a, b) if j - i > 0)[-k:]))
