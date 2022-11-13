# Write your code here
import functools
import operator
 
n = int(input())
a = map(int, input().strip().split())
print(1 if functools.reduce(operator.xor, a) else -1)
