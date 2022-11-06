p,s,t,h,x=map(int,input().split(" "))
sm=0
t1=0
t2=0
while x:
    if s>t:
        t1+=1
    else:
        t2+=1
    s-=1
    x-=1
#print(t1,t2)
print(p*t1+h*t2)
