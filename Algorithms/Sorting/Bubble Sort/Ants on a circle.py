N, M, T = map(int, input().split())

positions = []

for _ in range(M):
    x, y = map(int, input().split())

    final_pos = ((x - 1 + y * T) % N) + 1
    positions.append(final_pos)

positions.sort()

print(*positions)
