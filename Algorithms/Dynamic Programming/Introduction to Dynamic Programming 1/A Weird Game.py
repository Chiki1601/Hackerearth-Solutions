# Write your code here
from bisect import bisect_left
 
q = int(input())
for _ in range(q):
    s = input().strip()
    t = input().strip()
    n = len(s)
    m = len(t)
    count = j = 0
    dp = []
    for i in range(n):
        if j < m and s[i] == t[j]:
            count += 1
            j += 1
        dp.append(count)
    ans = 0
    for i in range(n - 1, -1, -1):
        idx = bisect_left(dp, m)
        if m == 0:
            idx = - 1
        ans += i - idx
        if m > 0 and s[i] == t[m - 1]:
            m -= 1
    print(ans)
