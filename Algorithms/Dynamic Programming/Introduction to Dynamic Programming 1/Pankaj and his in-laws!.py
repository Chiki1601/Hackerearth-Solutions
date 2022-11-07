# Write your code here
t = int(input())
sequence = list(map(int, input().strip().split()))
dp = [1] * t
for i in range(1, t):
    for j in range(i - 1, -1, -1):
        if sequence[j] < sequence[i]:
            dp[i] = max(dp[i], dp[j] + 1)
print(bin(max(dp))[2:])
