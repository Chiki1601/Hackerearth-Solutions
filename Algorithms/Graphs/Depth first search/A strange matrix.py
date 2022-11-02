from collections import deque
 
moves = ((-1, 0), (1, 0), (0, -1), (0, 1))
 
 
def check(val, t, cell_val, len_row, len_col, mt):
    seen = [[False] * m for _ in range(n)]
    stack = deque([(0, 0)])
    while stack:
        x, y = stack.pop()
        if x == len_row - 1 and y == len_col - 1:
            return True
        for mx, my in moves:
            nx = x + mx
            ny = y + my
            if 0 <= nx < len_row and 0 <= ny < len_col and not seen[nx][ny] and min(cell_val, mt[nx][ny] + t) == val:
                stack.append((nx, ny))
                seen[nx][ny] = True
    return False
 
 
n, m, c = map(int, input().strip().split())
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().strip().split())))
low = -1
high = c
while high - low > 1:
    mid = (low + high) // 2
    if check(min(c, matrix[0][0] + mid), mid, c, n, m, matrix):
        high = mid
    else:
        low = mid
print(high)
