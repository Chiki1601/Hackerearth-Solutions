 
from functools import lru_cache
from math import sqrt, gcd
 
 
def is_prime(x):
    if x <= 1:
        return False
    if x <= 3:
        return True
    if x % 2 == 0 or x % 3 == 0:
        return False
    for i in range(5, int(sqrt(x)) + 1, 2):
        if x % i == 0:
            return False
    return True
 
 
@lru_cache(maxsize=None)
def count_prime(x, prime_list):
    return sum(not x % i for i in prime_list)
 
 
t = int(input())
primes = tuple(i for i in range(2, 51) if is_prime(i))
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    ans = a.count(1)
    a = list(filter(lambda x: 1 != x, a))
    while a:
        a = sorted(a, key=lambda x: count_prime(x, primes))
        a = list(filter(lambda x: 1 == gcd(x, a[0]), a))
        ans += 1
    print(ans)
