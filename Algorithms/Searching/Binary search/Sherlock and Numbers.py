from bisect import bisect
 
t = int(input())
for _ in range(t):
    n, k, p = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    if n - k < p:
        print(-1)
    else:
        while True:
            index = bisect(a, p)
            if index == 0:
                break
            a = a[index:]
            p += index
        print(p)
