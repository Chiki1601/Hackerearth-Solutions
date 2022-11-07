from itertools import accumulate
 
t = int(input())
for _ in range(t):
    n, q = map(int, input().strip().split())
    coordinates = list(map(int, input().strip().split()))
    ranges = list(map(int, input().strip().split()))
    pos = [0] * (2 * n + 2)
    neg = [0] * (2 * n + 2)
    for i in range(n):
        if coordinates[i] > 0:
            pos[max(1, coordinates[i] - ranges[i])] += 1
            pos[coordinates[i] + ranges[i] + 1] -= 1
        else:
            x = abs(coordinates[i])
            neg[max(1, x - ranges[i])] += 1
            neg[x + ranges[i] + 1] -= 1
    pos = list(accumulate(pos))
    neg = list(accumulate(neg))
    for _ in range(q):
        k = int(input())
        print(pos[k] if k > 0 else neg[abs(k)])
