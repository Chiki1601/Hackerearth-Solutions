from collections import Counter
t=int(input())
alpha="qwertyuiopasdfghjklzxcvbnm"
for i in range(t):
    s=input()
    l=[]
    d=dict(Counter(s))
    for k in d.keys():
        l.append(k)
    #print(l)
    for j in alpha:
        if j in l:
            val=1
            continue
        if j not in l:
            val=0
            break
    if val==1:
        print("YES")
    else:
        print("NO")
