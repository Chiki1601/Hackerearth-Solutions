from operator import add
 
t = int(input())
for _ in range(t):
    n = int(input())
    ia = [n - int(i) for i in input().strip().split()]
    ir = [-int(i) for i in input().strip().split()]
    ir.reverse()
    a = list(map(add, ia, ir))
    if min(a) < 1 or len(set(a)) < n:
        print(-1)
    else:
        print(*a)
