# Write your code here
t = int(input())
for _ in range(t):
    s = input()
    ln = len(s)
    mid = ln // 2
    x = s[:mid]
    y = s[mid + ln % 2:][::-1]
    comp = tuple((x[i], y[i]) for i in range(mid) if x[i] != y[i])
    if ln % 2:
        z = s[mid]
        if len(comp) == 1:
            print('Yes' if z in comp[0] else 'No')
            continue
    if len(comp) == 2:
        print('Yes' if comp[0] == comp[1] or comp[0] == comp[1][::-1] else 'No')
    elif len(comp) == 0:
        print('Yes')
    else:
        print('No')
