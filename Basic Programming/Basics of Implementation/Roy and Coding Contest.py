t=int(input())
for i in range(t):
    npc,npd=map(int,input().split())
    time=0
    cnt=0
    pc=1
    pd=1
    if npc==1:
        cnt=0
    else:
        while time<npc:
            if pc<npd:
                time = time + pc
                pc = pd
                pd = pd + pd
                cnt+=1
            elif (pc >= npd):
                time=time+npd
                cnt+=1
            pd+=1
 
    print(cnt+1)
