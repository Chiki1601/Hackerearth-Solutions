n,k,x = map(int,input().split())
i = 1
lis = [i for i in range(1,n+1)]
flag =0
size = n
while(size!=1):
    noOfKills = x%k
    if(noOfKills >= size):
        print(x)
        flag = 1
        break
    else:
        s = (lis.index(x)+1)%size
        e = (lis.index(x)+1 + noOfKills)%size
        if(e < s):
            lis[ s: ]=[]
            lis[:e] = []
        else:
            lis[ s : e ]=[]
    if(noOfKills !=0):
        size = size - noOfKills
 
    x = lis[(lis.index(x)+1)%size]
if(flag==0):
    print(lis[0])
