t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().strip().split()))
    min_val = float('inf')
    for i in range(n - 1):
        min_val = min(min_val, a[i] ^ a[i + 1])
    print(min_val)
