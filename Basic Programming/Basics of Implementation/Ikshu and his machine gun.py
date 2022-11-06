s=int(input())
a=[int(x) for x in input().split()]
a=sorted(a)
b=[a[i]-i for i in range(s)]
print(*b)
