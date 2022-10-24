# Write your code here
s = input()
t = input()
len_s = len(s)
i = 0
for c in t:
    if c == s[i]:
        i += 1
        if i == len_s:
            break
print(i)
