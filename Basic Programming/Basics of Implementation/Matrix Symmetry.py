t = int(input())
for _ in range(t):
    n = int(input())
    matrix = [input().strip() for _ in range(n)]
    m = n // 2
    h = v = True
    for i in range(m):
        if matrix[i] != matrix[n - 1 - i]:
            h = False
            break
    for i in range(n):
        for j in range(m):
            if matrix[i][j] != matrix[i][n - 1 - j]:
                v = False
                break
        else:
            continue
        break
    if v and h:
        print("BOTH")
    elif h:
        print("HORIZONTAL")
    elif v:
        print("VERTICAL")
    else:
        print("NO")
