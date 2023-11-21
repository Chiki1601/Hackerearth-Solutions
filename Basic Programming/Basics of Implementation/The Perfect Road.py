t = int(input())
for _ in range(t):
    s, x, n = map(int, input().strip().split())
    speeds = list(map(int, input().strip().split()))
    m = max(speeds)
    if speeds.count(m) > 1:
        print('Many Roads')
    else:
        print(speeds.index(m) + 1)
