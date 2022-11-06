import math
t=int(input())
for i in range(t):
    t0,t1,t2,v1,v2,d=map(int,input().split(" "))
    if t0>t1 and t0>t2:
        print("-1")
    else:
        d1=(d*60)/v1
        d2=(d*60)/v2
        if(t0>t1 and t0<=t2):
            res=d2+t2
        elif (t0>t2 and t0<=t1): 
            res=d1+t1
        elif (t0<=t1 and t0<=t2):
            res=min((t1+d1),(t2+d2));
        print(math.ceil(res))
