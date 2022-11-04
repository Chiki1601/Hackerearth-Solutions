mod = 1000000007
n, k = map(int, input().strip().split())
ans = 0
f = 1
e = 1
for i in range(1, k + 1):
    f *= i
    e *= n + i - 1
    ans += e // f
    ans %= mod
print(ans)
