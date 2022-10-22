def NotinRange(R, L, n):
    # Write your code here
    ranges = {}
    for i in range(n):
        ranges[L[i]] = R[i]
    total = end = 0
    mx = 1000000
    for start in sorted(ranges):
        if end < start:
            total += (start + end) * (start - end - 1) / 2
        end = max(end, ranges[start])
    total += (mx + end + 1) * (mx - end) / 2
    return int(total)
 
 
n = int(input())
L, R = [], []
for _ in range(n):
    x, y = map(int, input().strip().split())
    L.append(x)
    R.append(y)
out_ = NotinRange(R, L, n)
print(out_)
