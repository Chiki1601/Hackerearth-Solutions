n, m = map(int, input().strip().split())
ans = 1
for i in range(1, m + 1):
    ans = ans * i % 1000000007
print(ans)
