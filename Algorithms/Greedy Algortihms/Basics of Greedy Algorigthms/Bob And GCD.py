t = int(input())
for _ in range(t):
    k, n = map(int, input().strip().split())
    a = map(int, input().strip().split())
    mid = k / 2
    step = 0
    for i in a:
        mod = i % k
        if i < k:
            step += k - i
        elif mod > mid:
            step += k - mod
        else:
            step += mod
    print(step)
