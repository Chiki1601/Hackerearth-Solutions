t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    b = sorted(a)
    count = 0
    while b:
        if len(b) >= 2 and b[-1] - b[-2] <= 2:
            b.pop()
        b.pop()
        count += 1
    print(count)
