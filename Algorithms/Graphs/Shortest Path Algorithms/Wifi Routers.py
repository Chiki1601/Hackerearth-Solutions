#Write your code here
from math import sqrt
from sys import stdin
 
t = int(stdin.readline())
for _ in range(t):
    n, m = map(int, stdin.readline().strip().split())
    routers = []
    for _ in range(n):
        x, y = map(int, stdin.readline().split())
        routers.append((x, y))
    users = []
    for _ in range(m):
        x, y = map(int, stdin.readline().split())
        users.append((x, y))
    total = n + m
    both = users + routers
    matrix = [[0] * total for _ in range(total)]
    for i in range(m):
        for j in range(i):
            matrix[i][j] = matrix[j][i] = (both[i][0] - both[j][0]) ** 2 + (both[i][1] - both[j][1]) ** 2
    for i in range(m):
        for j in range(m, total):
            matrix[i][j] = matrix[j][i] = (both[i][0] - both[j][0]) ** 2 + (both[i][1] - both[j][1]) ** 2
    for i in range(m):
        for j in range(m):
            for k in range(j):
                a = max(matrix[j][i], matrix[i][k])
                if matrix[j][k] > a:
                    matrix[j][k] = matrix[k][j] = a
            for k in range(m, total):
                a = max(matrix[j][i], matrix[i][k])
                if matrix[j][k] > a:
                    matrix[j][k] = matrix[k][j] = a
    result = 0
    for i in range(m, total):
        result = max(result, max(matrix[i][:m]))
    print(f'{sqrt(result):.6f}')
