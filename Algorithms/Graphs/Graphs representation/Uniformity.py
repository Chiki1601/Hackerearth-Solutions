n, k = map(int, input().strip().split())
s = input()
mx = 0
ans = 0
count = {i: 0 for i in 'abc'}
for i in range(len(s)):
    count[s[i]] += 1
    mx = max(mx, count[s[i]])
    if ans - mx < k:
        ans += 1
    else:
        count[s[i - ans]] -= 1
print(ans)
