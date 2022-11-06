t=int(input())
for i in range(t):
    a,b=input().split()
    ar=int(a[::-1])
    br=int(b[::-1])
    res=str(ar+br)
    print(int(res[::-1]))
