from collections import Counter
import math
n=int(input())
s=input()
d=dict(Counter(s))
#print(d)
for i in d.keys():
    if i=="v":
        d[i]=math.ceil(d[i]/2)
#print(d)
#print("min: ",sum(d.values()))
c=dict(Counter(s))
for i in c.keys():
    if i=="w":
        c[i]*=2
#print(c)
#print("max: ",sum(c.values()))
print(sum(d.values()),sum(c.values()))c
