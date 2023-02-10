# Write your code here
from collections import defaultdict
 
mod = 1000000007
 
t = int(input())
for _ in range(t):
    n = int(input())
    adj = [defaultdict(int) for _ in range(n)]
    for i in range(n):
        for j in map(int, input().strip().split()):
            adj[i][j] += 1
    ans = defaultdict(int)
    part = adj[1:]
    for i in adj[0]:
        temp = adj[0][i]
        count = 0
        for j in part:
            count += 1
            k = j[i + count]
            if k == 0:
                temp = 0
                break
            else:
                temp *= k
                temp %= mod
        ans[i - 1] = temp
    q = int(input())
    for _ in range(q):
        s, d = map(int, input().strip().split())
        if d - s - 1 != n:
            print(0)
        else:
            print(ans[s])
