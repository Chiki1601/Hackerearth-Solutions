import sys
from bisect import bisect
 
n, q = map(int, sys.stdin.readline().strip().split())
elements = sorted(map(int, sys.stdin.readline().strip().split()))
mod = 1000000007  # 10 ** 9 + 7
p = [1] * (n + 1)
for i in range(1, n + 1):
    p[i] = p[i - 1] * 2 % mod
for _ in range(q):
    query = sys.stdin.readline().strip().split()
    query_type = query[0]
    k = int(query[1])
    if query_type == '<':
        i = bisect(elements, k - 1)
        print(p[i] % mod)
    elif query_type == '=':
        i = bisect(elements, k)
        j = bisect(elements, k - 1)
        print((p[i] - p[j]) % mod)
    else:
        i = bisect(elements, k)
        print((p[n] - p[i]) % mod)
