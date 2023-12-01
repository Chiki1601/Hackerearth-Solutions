t = int(input())
for _ in range(t):
    m, n = map(int, input().strip().split())
    a = input().strip()
    b = input().strip()
    count = float("inf")
    for c in set(b):
        count = min(count, a.count(c) // b.count(c))
    print(count)
