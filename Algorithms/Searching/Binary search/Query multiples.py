# Write your code here
import math
from collections import defaultdict
 
n, q = map(int, input().strip().split())
arr = list(map(int, input().strip().split()))
 
factors = defaultdict(list)
for i in range(n):
    num = arr[i]
    count = int(math.sqrt(num)) + 1
    divisible = set()
    for j in range(1, count):
        if num % j == 0:
            divisible.add(j)
            divisible.add(num // j)
    for j in divisible:
        factors[j].append(i)
 
for _ in range(q):
    index, x = map(int, input().strip().split())
    index = index - 1
    factors_x = factors[x]
    ln = len(factors_x)
    if not ln:
        print(0)
        continue
    for i in range(ln):
        if factors_x[i] >= index:
            print(ln - i)
            break
    else:
        print(0)
