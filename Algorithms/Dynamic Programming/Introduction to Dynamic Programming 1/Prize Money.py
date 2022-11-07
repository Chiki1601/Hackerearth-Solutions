# Write your code here
n = int(input())
arr = sorted(map(int, input().strip().split()))
ln = arr[-1] * 2 + 1
dp = [False] * ln
dp[0] = True
for i in range(arr[0], arr[-1]):
    for j in arr:
        if i - j >= 0 and dp[i - j]:
            dp[i] = True
            break
for i in range(arr[-1] + 1, ln):
    for j in arr:
        if i - j >= 0 and dp[i - j]:
            dp[i] = True
            break
    if not dp[i]:
        print(i)
        break
else:
    print('Fake Offer!')
