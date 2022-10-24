# Write your code here
s = input()
m = int(input())
 
 
def floyd_warshall(adj):
    dist = adj.copy()
    for k in range(26):
        for i in range(26):
            for j in range(26):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist
 
 
graph = [[float('inf')] * 26 for _ in range(26)]
for _ in range(m):
    x, y, c = input().strip().split()
    c = int(c)
    x = ord(x) - 97
    y = ord(y) - 97
    graph[x][y] = min(graph[x][y], c)
    graph[y][x] = min(graph[y][x], c)
d = floyd_warshall(graph)
ans = 0
left = 0
right = len(s) - 1
while left < right:
    if s[left] != s[right]:
        x = ord(s[left]) - 97
        y = ord(s[right]) - 97
        ans += min(d[x][y], d[y][x])
    left += 1
    right -= 1
print(ans)
