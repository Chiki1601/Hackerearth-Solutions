n = int(input())
x = 0
logs = ''
for _ in range(n):
    s = input().strip().replace('E', 'S')
    x = max(x, len(max(s.split('S'))))
    logs += s
print(x, len(max(logs.split('S'))))
