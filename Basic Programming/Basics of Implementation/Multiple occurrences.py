t = int(input())
for _ in range(t):
    x = int(input())
    a = input().strip().split()
    idxes = {}
    ans = 0
    for i in range(x):
        if a[i] in idxes:
            ans += i - idxes[a[i]]
        idxes[a[i]] = i
    print(ans)
