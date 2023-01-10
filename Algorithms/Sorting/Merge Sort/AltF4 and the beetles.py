# Write your code here
t = int(input())
for _ in range(t):
    n, a, b, c = map(int, input().split())
    beetles = []
    for i in range(n):
        p, q = map(int, input().split())
        beetles.append((p, 0))
        beetles.append((q, 1))
    beetles.sort(key=lambda x: x[0] * 2 + x[1])
    total = n * a
    ba = b - a
    cb = c - b
    ans = total
    for beetle in beetles:
        if beetle[1]:
            total += cb
        else:
            total += ba
        ans = max(ans, total)
    print(ans)
