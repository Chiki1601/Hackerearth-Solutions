mapper = {'a': 'b', 'e': 'f', 'i': 'j', 'o': 'p', 'u': 'v'}
t = int(input())
for _ in range(t):
    s = input().strip()
    q = int(input())
    if len(s) == 1 or q == 0:
        print(s)
        continue
    s = list(s)
    for i, c in enumerate(s):
        if c in mapper:
            s[i] = mapper[c]
            q -= 1
            if q == 0:
                break
    print(''.join(s))
