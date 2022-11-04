from math import factorial
 
t = int(input())
for _ in range(t):
    n = int(input())
    print(factorial(2 * n) // factorial(n) // factorial(n + 1))
