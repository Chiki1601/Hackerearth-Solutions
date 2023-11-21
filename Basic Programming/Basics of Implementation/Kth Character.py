s = input()
for i in range(len(s) - 1):
    if s[i] > s[i + 1]:
        s = s.replace(s[i], '')
        break
print(s)
