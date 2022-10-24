t = int(input())
for _ in range(t):
    s = input()
    res = -1
    for c in set(s):
        left = s.index(c)
        right = s.rindex(c)
        res = max(res, right - left - 1)
    print(res)
