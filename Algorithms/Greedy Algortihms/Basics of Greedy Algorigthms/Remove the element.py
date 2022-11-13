# Write your code here
mod = 1000000007
t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().strip().split()), reverse=True)
    total = 0
    prod = 1
    for i, x in enumerate(a):
        prod = prod * (i + 1) % mod
        total = (total + x * prod) % mod
    print(total)
