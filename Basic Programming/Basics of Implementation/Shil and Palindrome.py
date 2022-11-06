import sys
from collections import Counter
s = input().strip()
c = Counter(s)
pal = ""
mid = ""
odd = 0
 
for k,v in c.items():
    if v%2:
        odd+=1
        mid+=k
        v-=1
    pal+=k*(v//2)
 
if odd > 1 :
    print("-1")
else:
    pal = "".join(sorted(pal))
    print(pal+mid+pal[::-1])
