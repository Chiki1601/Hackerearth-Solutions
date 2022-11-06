n=int(input())
al=n
a=list(map(int,input().split(" ")))
for i in range(n):
    if a[i]>=al:
        print(i+1)
        break
    else:
        al-=1
