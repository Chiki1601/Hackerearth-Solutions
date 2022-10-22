s = input().strip()
bal = mn = count = 0
for c in s:
    if c == '(':
        bal += 1
    else:
        bal -= 1
    if bal < mn:
        mn = bal
        count = 0
    count += mn == bal
print(0 if bal else count)
