t=int(input())
for i in range(t):
    n=int(input())
    d=[int(x) for x in input().split()]
    #print(d)
    m=int(input())
    i=0
    while m>0:
        #print(m)
        #print("D: ",d[i%n])
        m-=d[i%n]
        if m>0:
            i+=1
    else:
        print((i%n)+1)
