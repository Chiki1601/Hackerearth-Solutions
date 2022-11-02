# Write your code here
n = int(input())
for _ in range(n - 1):
    input()
statuses = ''.join(input().strip().split())
roads = list(map(len, statuses.split('1')))
ans = max(roads)
ans -= ans in (roads[0], roads[-1])
print(ans + 2)
