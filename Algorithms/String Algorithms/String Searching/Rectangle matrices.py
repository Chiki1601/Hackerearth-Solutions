# Write your code here
from math import gcd
from sys import stdin
 
t = int(stdin.readline())
for _ in range(t):
    a, b = list(map(int, stdin.readline().strip().split()))
    c = gcd(a, b)
    print('No' if c & c - 1 else 'Yes')
