t = int(input())
for _ in range(t):
    n, m = map(int, input().strip().split())
    ans = 0
    for _ in range(n):
        cells = input().strip()
        ans = max(ans, cells.count('#'))
    print(ans)
