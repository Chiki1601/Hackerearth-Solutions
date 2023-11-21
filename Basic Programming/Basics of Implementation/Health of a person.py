t = int(input())
for _ in range(t):
    n, m = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))
    unhealthy_days = [-1] * n
    for i, point in enumerate(b, 1):
        for j in range(i - 1, n, i):
            if a[j] <= point and unhealthy_days[j] == -1:
                unhealthy_days[j] = i
    for i in unhealthy_days:
        print(i)
