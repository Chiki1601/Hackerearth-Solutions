n,q=map(int,input().split(" "))
a=[int(x) for x in input().split(" ")]
for i in range(q):
    l,r=map(int,input().split())
    cnt=0
    for j in range(l-1,r):
        if "11" in bin(a[j])[2:]:
            cnt+=1
    print(cnt)
