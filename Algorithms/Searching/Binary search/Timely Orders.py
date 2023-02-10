import sys
from bisect import bisect_left
 
prev = 0
totals = []
times = []
q = int(sys.stdin.readline())
for _ in range(q):
    t, x, k = map(int, sys.stdin.readline().strip().split())
    if t == 1:
        totals.append(x + prev)
        prev += x
        times.append(k)
    if t == 2:
        i = bisect_left(times, k - x)
        print(prev - totals[i - 1] if i else prev)
