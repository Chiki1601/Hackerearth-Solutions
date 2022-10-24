s = input()
ans = ''
for i in range(len(s)):
    ans += s[i].upper() if not i or s[i - 1] == ' ' else s[i]
print(ans)
