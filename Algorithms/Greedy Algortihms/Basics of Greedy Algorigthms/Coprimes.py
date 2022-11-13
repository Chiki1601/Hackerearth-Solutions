import math
 
n = int(input())
res = []
for i in range(1, n - 1):
    if math.gcd(i, n) == 1:
        res.append(i)
print(max(res))
