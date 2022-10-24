for _ in range(int(input())):
    n,m = map(int,input().split())
    arr = list(map(int,input().split()))
 
    for i in range(n-1):
        for j in range(n-1-i):
            if(arr[j]>arr[j+1]):
                arr[j], arr[j+1] = arr[j+1], arr[j]
    print((sum(arr[m:]))-(sum(arr[:n-m])))
