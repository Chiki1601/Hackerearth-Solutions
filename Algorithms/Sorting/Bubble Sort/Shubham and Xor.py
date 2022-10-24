# Write your code here
from collections import Counter
 
n = int(input())
a = input().strip().split()
counter = Counter(a)
pairs = sum((i * (i - 1)) // 2 for i in counter.values() if i > 1)
print(pairs)
