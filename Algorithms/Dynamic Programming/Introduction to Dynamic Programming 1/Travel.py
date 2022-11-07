# Write your code here
from collections import defaultdict
 
t = int(input())
for _ in range(t):
    n, k = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    dec = defaultdict(list)
    for i in range(n):
        dec[a[i]].append(i)
    for i in dec:
        dec[i].sort()
    left = [0]
    right = [0]
    if 1 not in dec:
        print(0)
    else:
        for i in range(2, k + 1):
            if i not in dec:
                break
            else:
                last_left = left[-1]
                last_right = right[-1]
                left.append(
                    max(last_right + abs(dec[i - 1][-1] - dec[i][0]), last_left + abs(dec[i - 1][0] - dec[i][0])))
                right.append(
                    max(last_right + abs(dec[i - 1][-1] - dec[i][-1]), last_left + abs(dec[i - 1][0] - dec[i][-1])))
        print(max(left[-1], right[-1]))
