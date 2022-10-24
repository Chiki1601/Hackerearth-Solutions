# Write your code here
s = input()
ans = ''
for c in s:
    if c not in ans:
        ans = ans + c
print(ans)
