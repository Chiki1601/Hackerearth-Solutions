from bisect import bisect
from math import floor, sqrt, ceil
 
 
def generate_array(max_val):
    def generate_number(x):
        return x * floor(sqrt(x)) + ceil(x / 2)
 
    arr = [1]
    i = 0
    val = 0
    while val < max_val:
        val = arr[-1] + generate_number(i)
        arr.append(val)
        i += 1
    return arr
 
 
q = int(input())
queries = []
size = 0
for _ in range(q):
    l, r = map(int, input().strip().split())
    size = max(size, r)
    queries.append((l, r))
a = generate_array(size)
for left, right in queries:
    idx1 = bisect(a, left) - 1
    idx2 = bisect(a, right) - 1
    print(idx2 - idx1 + 1)
