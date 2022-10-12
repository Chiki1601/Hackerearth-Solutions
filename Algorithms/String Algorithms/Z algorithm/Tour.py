# Write your code here
n = int(input())
cities = []
for _ in range(n):
    cities.append(input().strip())
cost = []
for _ in range(n):
    cost.append(list(map(int, input().strip().split())))
p = int(input())
total = 0
i = 0
for _ in range(p):
    visit_city = input().strip()
    j = cities.index(visit_city)
    total += cost[i][j]
    i = j
print(total)
