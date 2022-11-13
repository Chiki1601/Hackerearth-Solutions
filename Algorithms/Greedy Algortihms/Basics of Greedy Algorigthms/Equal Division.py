n = int(input())
teams = []
for _ in range(n):
    a, b = map(int, input().strip().split())
    teams.append((a, b))
teams.reverse()
ans = 0
total = 0
for a, b in teams:
    a += total
    if a % b:
        total += b - a % b
print(total)
