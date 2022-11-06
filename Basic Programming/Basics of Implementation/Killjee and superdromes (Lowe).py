q=int(input())
a=[int(x) for x in input().split()]
for i in a:
    cnt=0
    for j in range(1,i+1):
        x=str('{0:b}'.format(j))
        if x==x[::-1] and str(j)==str(j)[::-1]:
            cnt+=1
    print(cnt)
