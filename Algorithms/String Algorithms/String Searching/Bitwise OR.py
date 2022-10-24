from functools import reduce
from operator import or_
 
t = int(input())
for _ in range(t):
    n, x = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    temp = reduce(or_, a, 0)
    if temp < x:
        print(0)
    else:
        subarrays = []
        temp = a[:]
        for i in range(n):
            flag = False
            for j in range(n - i):
                temp[j] = temp[j] | a[i + j]
                if temp[j] >= x:
                    subarrays.append([j + 1, j + i + 1])
                    flag = True
            if flag:
                break
        print(len(subarrays))
        for l, r in subarrays:
            print(l, r)
