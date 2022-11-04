s = input()
n = len(s)
count = 0
for i in range(n):
    for j in range(i + 1, n + 1):
        count += s[i:j] == s[i:j][::-1]
print(count)
