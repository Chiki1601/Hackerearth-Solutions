def checkBeautyFactor(n):
    su = 0
    for i in str(n):
        su+= int(i)
        
    if len(str(su))>1:
        su = checkBeautyFactor(str(su))
        
    return su
 
b,k = map(int,input().split())
 
 
if k == 9:
    if b==9:
        print(123456789)
    else:
        print(-1)
else:
    n = "1" + "0"*(k-1)
    while True:
        if "0" in str(n):
            n = int(n)
            n+=1
            continue
        n = str(n)
        if len(set(n)) != len(n):
            n = int(n)
            n+=1
            continue
            
        beautyFactor = checkBeautyFactor(str(n))
        
        if beautyFactor == b:
            print(n)
            break
            
        n = int(n)
        n+=1
        if len(str(n))>k:
            print(-1)
            break
