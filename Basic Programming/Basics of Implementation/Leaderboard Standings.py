from heapq import heappush, heappop
from sys import stdin

n = int(stdin.readline())
contestants = {}
for _ in range(n):
    c, t = stdin.readline().split()
    t = int(t)
    if c in contestants:
        contestants[c][0] -= 100
        contestants[c][1] += t
    else:
        contestants[c] = [-100, t, c]
heap = []
for c in contestants:
    heappush(heap, tuple(contestants[c]))
i = 1
while heap:
    contestant = heappop(heap)
    print(i, contestant[2])
    i += 1
