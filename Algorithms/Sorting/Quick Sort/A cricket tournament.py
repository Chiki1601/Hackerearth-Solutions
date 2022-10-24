n = int(input())
a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))
a.sort(reverse=True)
b.sort()
ans = 0
for x, y in zip(a, b):
    if x > y:
        ans += x - y
    else:
        break
print(ans)
