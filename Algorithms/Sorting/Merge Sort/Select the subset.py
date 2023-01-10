from bisect import bisect_left
 
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))
    c = sorted(zip(a, b))
    subsets = []
    for _, x in c:
        idx = bisect_left(subsets, x)
        subsets[idx: idx + 1] = [x]
    print(len(subsets))
