# Write your code here
t = int(input())
for _ in range(t):
    n, m = map(int, input().strip().split())
    dist = [[float('inf')] * n for _ in range(n)]
    for _ in range(m):
        x, y, c = map(int, input().strip().split())
        x -= 1
        y -= 1
        dist[x][y] = min(dist[x][y], c)
        dist[y][x] = min(dist[y][x], c)
    s, a, h = map(lambda v: int(v) - 1, input().strip().split())
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    ans = 0
    for i in range(n):
        if i != s and i != a and i != h:
            ans = max(ans, dist[s][i] + 2 * dist[i][a] + dist[i][h])
    print(ans)
