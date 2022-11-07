from bisect import bisect_left
 
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    s = []
    for i in reversed(a):
        if not s or i > s[-1]:
            s.append(i)
        else:
            s[bisect_left(s, i)] = i
    print(len(s))
