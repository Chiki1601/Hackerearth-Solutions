# Write your code here
from bisect import bisect_right
 
q = int(input())
m = 1000000
sieve = [True] * (m // 2)
for i in range(3, int(m ** 0.5) + 1, 2):
    if sieve[i // 2]:
        sieve[i * i // 2::i] = [False] * ((m - i * i - 1) // (2 * i) + 1)
primes = [2] + [2 * i + 1 for i in range(1, m // 2) if sieve[i]]
for _ in range(q):
    n = int(input())
    print(bisect_right(primes, n))
