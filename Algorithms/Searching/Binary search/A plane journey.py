n, m = map(int, input().strip().split())
a = sorted(map(int, input().strip().split()), reverse=True)
b = sorted(map(int, input().strip().split()), reverse=True)
if a[0] > b[0]:
    print(-1)
else:
    min_time = 1
    i = j = 0
    while i < len(a):
        if j < len(b) and a[i] <= b[j]:
            j += 1
        elif a[i] <= b[j - 1]:
            min_time += 2
        i += 1
    print(min_time)
