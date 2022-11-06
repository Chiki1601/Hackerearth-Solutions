url=input()
al=url.split("?")
#print(al)
bl=al[1].split("&")
#print(bl)
d={}
cnst=["username", "pwd", "profile", "role", "key"]
for i in bl:
    k,v=(i.split("="))
    if k in cnst:
        print(k,": ",v,sep="")
    #d[k]=v
#print(d)
