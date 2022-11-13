from heapq import heappop, heappush
 
t = int(input())
moves = ((1, 0, 0), (0, 1, 0), (0, 0, 1))
for _ in range(t):
    x, y, z = map(int, input().strip().split())
    k = int(input())
    b1 = sorted(map(int, input().strip().split()), reverse=True)
    b2 = sorted(map(int, input().strip().split()), reverse=True)
    b3 = sorted(map(int, input().strip().split()), reverse=True)
    heap = [(-(b1[0] + b2[0] + b3[0]), 0, 0, 0)]
    visited = {(0, 0, 0)}
    ans = 0
    while k:
        total, bx, by, bz = heappop(heap)
        ans -= total
        for mx, my, mz in moves:
            nx = bx + mx
            ny = by + my
            nz = bz + mz
            if nx < x and ny < y and nz < z and (nx, ny, nz) not in visited:
                heappush(heap, (-(b1[nx] + b2[ny] + b3[nz]), nx, ny, nz))
                visited.add((nx, ny, nz))
        k -= 1
    print(ans)
