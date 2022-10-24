t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    ans = max(s)
    idx = s.index(ans)
    for i in range(ord(ans) - 1, ord('a') - 1, -1):
        try:
            idx = s.index(chr(i), idx + 1)
            ans += chr(i)
        except ValueError:
            pass
    print(ans)
