n,q=map(int,input().split())
a=[x for x in input().split(" ")]
for i in range(q):
    z=int(input())
    print(len(set(a[z-1:n])))
