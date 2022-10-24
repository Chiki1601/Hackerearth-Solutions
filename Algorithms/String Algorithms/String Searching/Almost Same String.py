# Write your code here
from string import ascii_lowercase
from collections import Counter
 
 
def dist(c1, c2):
    diff = abs(ord(c1) - ord(c2))
    return min(diff, ord('z') - diff - ord('a') + 1)
 
 
t = int(input())
for _ in range(t):
    a = input()
    b = input()
    k = int(input())
    counter = Counter(a + b)
    min_step = float('inf')
    for start in ascii_lowercase:
        end = chr((((ord(start) - ord('a')) + k) % 26) + ord('a'))
        step = 0
        for c in ascii_lowercase:
            if (start <= end and (c < start or c > end)) or end < c < start:
                step += counter[c] * min(dist(c, start), dist(c, end))
        min_step = min(min_step, step)
    print(min_step)
