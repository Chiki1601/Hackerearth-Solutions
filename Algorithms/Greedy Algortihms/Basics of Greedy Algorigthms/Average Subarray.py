# Write your code here
t = int(input())
for _ in range(t):
    n, k = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    count = ans = 0
    for i in a:
        if i:
            count += 1
            if count == k:
                ans += 1
                count = 0
        else:
            count = 0
    print(ans)
