mx = 10 ** 12
n = int(input())
for _ in range(n):
    digits = list(map(int, input().strip()))
    ln = len(digits)
    dp = [-1] * ln + [0]
    for _ in range(4):
        temp = [-1] * (ln + 1)
        for i in range(ln):
            if 0 == digits[i]:
                if dp[i + 1] >= 0:
                    temp[i] = max(temp[i], dp[i + 1])
            else:
                x = 0
                for j in range(i, ln):
                    x = x * 10 + digits[j]
                    if x > mx:
                        break
                    if dp[j + 1] >= 0:
                        temp[i] = max(temp[i], x + dp[j + 1])
        dp = temp
    print(dp[0] if dp[0] >= 0 else 'unlucky')
