from heapq import heapify, heappop, heappush


def check(x, y, arr):
    heap = [-x, -y]
    heapify(heap)
    ln = len(arr)
    while len(heap) < ln:
        u = heappop(heap)
        v = heappop(heap)
        heappush(heap, u)
        heappush(heap, v)
        heappush(heap, u + v)
        heappush(heap, u - v)
    heap = sorted(-i for i in heap)
    return heap == arr


t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().strip().split()))
    if len(a) > 4 and a[-1] < a[3] * 2:
        print('NO')
        continue
    if len(a) == 4:
        a1, a2, a3 = a[0:3]
        if check(a3, a1, a):
            print('YES')
            print(a3, a1)
            continue
        if check(a3, a2, a):
            print('YES')
            print(a3, a2)
            continue
    a1 = a[1]
    a2 = a[3]
    if check(a2, a1, a):
        print("YES")
        print(a2, a1)
        continue
    print("NO")
