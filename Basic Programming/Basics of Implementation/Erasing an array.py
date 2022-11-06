t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    c = 1
    for i in range(n-1):
        if arr[i] == 1 and arr[i+1]==0:
            c+=1
    print(c)
