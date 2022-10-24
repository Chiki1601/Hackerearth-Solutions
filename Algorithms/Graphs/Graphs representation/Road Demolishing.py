# Write your code here
t = int(input())
for _ in range(t):
    n, q = map(int, input().strip().split())
    q -= 1
    ans = n * n - (n % q) * ((n + q - 1) // q) ** 2 - (q - n % q) * (n // q) ** 2
    ans //= 2
    ans = n * (n - 1) // 2 - ans
    print(abs(ans))
