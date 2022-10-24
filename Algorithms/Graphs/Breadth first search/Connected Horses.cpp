import math
from collections import deque
 
 
def count_photographs(adjacency, rows, cols):
    moves = ((2, 1), (1, 2), (2, -1), (-1, 2), (-2, 1), (1, -2), (-2, -1), (-1, -2))
    res = 1
    visited = set()
    for i in range(rows):
        for j in range(cols):
            if adjacency[i][j] and (i, j) not in visited:
                count = 0
                queue = deque([(i, j)])
                while queue:
                    u, v = queue.popleft()
                    if (u, v) not in visited:
                        visited.add((u, v))
                        count += 1
                        for move in moves:
                            move_u = u + move[0]
                            move_v = v + move[-1]
                            if 0 <= move_u < rows and 0 <= move_v < cols:
                                if adjacency[move_u][move_v]:
                                    queue.append((move_u, move_v))
                if count > 1:
                    res *= math.factorial(count)
                    res %= 1000000007
    return res
 
 
t = int(input())
for _ in range(t):
    n, m, q = map(int, input().strip().split())
    chess_board = [[False] * m for _ in range(n)]
    for _ in range(q):
        x, y = map(int, input().strip().split())
        chess_board[x - 1][y - 1] = True
    print(count_photographs(chess_board, n, m))
