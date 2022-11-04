# Write your code here
from functools import reduce
from math import factorial
 
mod = 1000000007
n, k = list(map(int, input().strip().split()))
bricks = sorted(map(int, input().strip().split()))
if bricks[0] != 1:
    bricks = [0] + bricks
if bricks[-1] != n:
    bricks.append(n + 1)
counter = []
for i in range(len(bricks) - 1):
    count = bricks[i + 1] - bricks[i]
    if count != 1:
        counter.append(count - 1)
x = reduce(lambda a, b: a * factorial(b) % mod, counter, 1)
length = len(counter)
total = sum(counter)
if bricks[0] == 0:
    length -= 1
    total -= counter[0]
if bricks[-1] == n + 1:
    length -= 1
    total -= counter[-1]
res = factorial(sum(counter)) * pow(x, mod - 2, mod) * pow(2, total - length, mod)
res %= mod
print(res)
