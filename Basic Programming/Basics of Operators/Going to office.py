d = int(input())
oc,of,od = map(int,input().split())
cs,cb,cm,cd = map(int,input().split())
temp = d- of
if temp > 0:
    costOnline = oc+ temp*od
else:
    costOnline = oc
 
time = d//cs
costOffline = cb + cm*time + cd*d
 
if costOnline<=costOffline:
    print("Online Taxi")
 
else:
    print("Classic Taxi")
