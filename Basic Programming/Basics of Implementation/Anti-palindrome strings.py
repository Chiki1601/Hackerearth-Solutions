t = int(input())
for _ in range(t):
    inp = input()
    s = ''.join(sorted(inp))
    if s == s[::-1]:
        print(-1)
    else:
        print(s)
