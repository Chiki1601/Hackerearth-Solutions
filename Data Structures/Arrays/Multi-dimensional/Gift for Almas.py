n = int(input())
matrix = []
for _ in range(n):
    matrix.append(input().strip().split())
symbols = list(input().strip())
instructions = sum(1 if i == 'R' else -1 for i in symbols)
if instructions in (1, -3):
    rotate_matrix = [['0'] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            rotate_matrix[i][j] = matrix[n - j - 1][i]
    matrix = rotate_matrix
elif instructions in (-1, 3):
    rotate_matrix = [['0'] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            rotate_matrix[i][j] = matrix[j][n - i - 1]
    matrix = rotate_matrix
for i in range(n):
    print(' '.join(matrix[i]))
