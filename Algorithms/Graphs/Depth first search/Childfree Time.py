# Write your code here
r, p = map(int, input().strip().split())
labyrinths = [[] for _ in range(r)]
for _ in range(p):
    r1, r2, t = map(int, input().strip().split())
    labyrinths[r1 - 1].append((r2 - 1, t))
 
 
def exploring(u, adjacency, seen, times):
    seen[u] = True
    spend_time = 0
    for v, time in adjacency[u]:
        if not seen[v]:
            spend_time = max(spend_time, 2 + time + exploring(v, adjacency, seen, times))
        else:
            spend_time = max(spend_time, 2 + time + times[v])
    times[u] = spend_time
    return spend_time
 
 
visited = [False] * r
time_rooms = [0] * r
max_time = 0
for i in range(r):
    if not visited[i]:
        max_time = max(max_time, exploring(i, labyrinths, visited, time_rooms))
print(max_time)
