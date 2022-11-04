# Write your code here
t = int(input())
mod = 1000000007
 
 
def count_rbs(string, size):
    if size == 1 or string[0] == ')' or string[size - 1] == '(':
        return 0
    dp = [[0] * (size + 1) for _ in range(size)]
    dp[1][1] = 1
    for i in range(2, size):
        for j in range(0, i + 1):
            if string[i - 1] == ')':
                dp[i][j] = dp[i - 1][j + 1] % mod
            elif string[i - 1] == '(':
                dp[i][j] = dp[i - 1][j - 1] % mod
            elif string[i - 1] == '?':
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod
    return dp[size - 1][1]
 
 
for _ in range(t):
    n = int(input())
    s = input()
    print(count_rbs(s, n))
