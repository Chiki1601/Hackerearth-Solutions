n=int(input())
a = [int(x) for x in input().split()] 
s,e=map(int,input().split(" "))
found=0
ll=[]
while found==0:
    x=a[s-1]
    if x==e or s==e:
        print("Yes")
        break
    elif x in ll:
        print("No")
        break
    else:
        s=x
        ll.append(s)
