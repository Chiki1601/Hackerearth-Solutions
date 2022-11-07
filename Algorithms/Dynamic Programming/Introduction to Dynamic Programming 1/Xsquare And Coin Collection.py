t = int(input())
for _ in range(t):
    n, k = map(int, input().strip().split())
    coins = list(map(int, input().strip().split()))
    mx = curr = 0
    for i in coins:
        if i <= k:
            curr += i
            mx = max(mx, curr)
        else:
            curr = 0
    print(mx)
