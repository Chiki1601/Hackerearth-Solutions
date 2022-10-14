from bisect import insort
 
n = int(input())
a = []
for _ in range(n):
    s = input().strip()
    insort(a, s)
    print(a.index(s))
