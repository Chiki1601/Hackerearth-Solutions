# Write your code here
from collections import Counter
 
t = int(input())
caching = []
max_num = 1001
for i in range(max_num):
    kit = set()
    for j in range(max_num):
        if (i | j) - (i & j) == i - j:
            kit.add(j)
    caching.append(kit)
for _ in range(t):
    n = int(input())
    a = map(int, input().strip().split())
    cnt = Counter(a)
    ans = 0
    for k, x in cnt.items():
        ans += sum(x * cnt[y] for y in caching[k])
    print(ans)
