n=int(input())
a=[int(x) for x in input().split(" ")]
b=[int(x) for x in input().split(" ")]
da=[]
db=[]
for i in range(n-1):
    da.append(abs(a[i]-a[i+1]))
mda=max(da)
for j in range(n-1):
    db.append(abs(b[j]-b[j+1]))
mdb=max(db)
if mda>mdb:
    print("Dom")
    print(mda)
elif mda<mdb:
    print("Brian")
    print(mdb)
else:
    print("Tie")
