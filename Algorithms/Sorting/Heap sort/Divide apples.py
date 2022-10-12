n =  int(input())
apples = list(map(int, input().split()))
avg = sum(apples) // n
calc = [0] * n
for i in range(n - 1):
    calc[i + 1] = calc[i] + apples[i] - avg
calc = sorted(calc)
med = -calc[n // 2]
ans = 0
for i in range(n):
    ans += abs(med + calc[i])
print(ans)
