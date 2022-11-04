# Write your code here
t = int(input())
for _ in range(t):
    n, p = map(int, input().strip().split())
    s = f = 1
    for i in range(1, p + 1):
        f = f * (n - i + 1) // i
        s += f
    print(s % 1000000007)
