from collections import Counter
 
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    if min(a) > 0:
        print(1)
    else:
        counter = Counter(a)
        b = sorted(counter.keys())
        mex = len(b)
        exists = True
        for i in range(len(b)):
            if i != b[i]:
                mex = i
                break
            if counter[b[i]] < 2:
                exists = False
                break
        if not exists:
            print(-1)
        else:
            print(a.index(mex - 1) + 1)
