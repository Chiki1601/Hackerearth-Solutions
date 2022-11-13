from bisect import bisect_left
from itertools import accumulate
 
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    totals = list(accumulate(a))
    left_calc = totals[-1] * 2 / 3
    idx = bisect_left(totals, left_calc)
    if idx > 0:
        left_calc -= totals[idx - 1]
    left_calc = int(left_calc + 0.5)
    left_count = idx + (left_calc >= a[idx] * 2 / 3)
    print(f'{left_count} {len(a) - left_count}')
