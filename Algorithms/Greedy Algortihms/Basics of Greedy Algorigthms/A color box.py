t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))
    req = have = 0
    for i in range(n):
        if a[i] != b[i]:
            if a[i] > b[i]:
                have += (a[i] - b[i]) // 2
            else:
                req += b[i] - a[i]
    if have >= req:
        print('Yes')
    else:
        print('No')
