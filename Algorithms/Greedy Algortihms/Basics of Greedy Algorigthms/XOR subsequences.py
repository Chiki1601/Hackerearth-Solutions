t = int(input())
for _ in range(t):
    n = int(input())
    a = map(int, input().strip().split())
    choose = set()
    s = []
    for i, v in enumerate(a, 1):
        if v not in choose:
            choose.add(v)
            s.append(i)
    print(len(s))
    print(*s)
