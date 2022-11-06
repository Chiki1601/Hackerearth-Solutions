for _ in range(int(input())):
    n,m,d=map(int,input().split())
    xloc=[]
    yloc=[]
    cnt=0
    for i in range(n):
        xL,yL=map(int,input().split())
        xloc.append(xL)
        yloc.append(yL)
    
    for j in range(m):
        x,y=map(int,input().split())
        for k in range(n):
            mDist = abs(x-xloc[k])+abs(y-yloc[k])
            if mDist<=d:
                cnt+=1
                break
    if cnt>(m/2):
        print("YES")
    else:
        print("NO")
