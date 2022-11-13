n = int(input())
a = sorted(map(int, input().strip().split()))
min_1 = a[0]
min_2 = a[1]
max_1 = a[-1]
max_2 = a[-2]
ans = 0
for i in a:
    if i < 0:
        ans += i * (min_1 if i != min_1 else min_2)
    elif i > 0:
        ans += i * (max_1  if i != max_1 else max_2)
print(ans % 1000000007)
