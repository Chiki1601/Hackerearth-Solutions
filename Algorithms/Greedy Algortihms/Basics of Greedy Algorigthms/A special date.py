from bisect import bisect_left
 
t = int(input())
pds = []
for d in range(1, 31):
    for m in range(1, 13):
        dm = str(d).zfill(2) + str(m).zfill(2)
        pds.append(int(dm[::-1]) * 10000 + m * 100 + d)
pds.sort()
for _ in range(t):
    d = input().strip()
    sd = int(d[4:] + d[2:4] + d[:2])
    i = bisect_left(pds, sd)
    if i < 1:
        print(-1)
    else:
        pd = str(pds[i - 1]).zfill(8)
        print(pd[6:] + pd[4:6] + pd[:4])
