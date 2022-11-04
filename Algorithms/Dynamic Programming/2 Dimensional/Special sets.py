from math import factorial
 
n = int(input())
left = 1
right = n
res = 0
while right >= left:
    res += factorial(right) // factorial(right - left)
    right -= 1
    left += 1
print(res % 1000000007)
