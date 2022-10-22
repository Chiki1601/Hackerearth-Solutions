from collections import Counter
 
t = int(input())
for _ in range(t):
    n, k = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    if n != k:
        mod = n / k
        for val in Counter(a).values():
            if val % mod:
                print('NO')
                break
        else:
            print('YES')
    else:
        print('YES')
