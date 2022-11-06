n=int(input())
s=[]
for i in range(n):
    s.append(input())
s=sorted(set("".join(s)))
print(len("".join(s)))
