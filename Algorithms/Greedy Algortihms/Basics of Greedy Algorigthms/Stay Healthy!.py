from heapq import heappush, heappop

t = int(input())
for _ in range(t):
    n, v = map(int, input().strip().split())
    pills = list(map(int, input().strip().split()))
    min_pills = 0
    heap = []
    for i, a in enumerate(pills):
        if i + v > n:
            break
        heappush(heap, -a)
        if v == 1:
            v += -heappop(heap)
            min_pills += 1
        else:
            v -= 1
    print(min_pills)
