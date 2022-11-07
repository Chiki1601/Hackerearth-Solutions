# Write your code here
n = int(input())
a = list(map(int, input().strip().split()))
pre = [1] * n
suf = [1] * n
for i in range(1, n):
    if a[i] > a[i - 1]:
        pre[i] = pre[i - 1] + 1
for i in range(n - 2, -1, -1):
    if a[i] < a[i + 1]:
        suf[i] = suf[i + 1] + 1
maks = 0
for i in range(1, n - 1):
    length = 0
    if a[i - 1] < a[i] < a[i + 1]:
        length = pre[i - 1] + suf[i + 1] + 1
    elif a[i - 1] < a[i + 1]:
        length = pre[i - 1] + suf[i + 1]
    else:
        length = max(pre[i - 1], suf[i + 1])
    maks = max(maks, length)
print(maks)
