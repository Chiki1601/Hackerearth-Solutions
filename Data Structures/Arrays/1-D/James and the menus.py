from collections import defaultdict
 
n, m = map(int, input().strip().split())
a = []
for _ in range(n):
    a.append(list(map(int, input().strip().split())))
counter = defaultdict(int)
for j in range(m):
    max_price = -1
    menu_idx = -1
    for i in range(n):
        if a[i][j] > max_price:
            max_price = a[i][j]
            menu_idx = i
    counter[menu_idx] += 1
menu_idx = -1
max_price = max(counter.values())
highest_avg = -1
for k, v in counter.items():
    if v == max_price:
        avg = sum(a[k]) / m
        if avg > highest_avg:
            highest_avg = avg
            menu_idx = k
print(menu_idx + 1)
