for tt in range(int(input())):
 a,b = map(int,input().split())
 ans=0
 ans = b-1 if b&1 else b-2
 print(ans if ans>=a else a&b)
