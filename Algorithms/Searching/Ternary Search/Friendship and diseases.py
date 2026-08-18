def solve():
    k, n, m = map(int, input().split())

    f = list(map(int, input().split()))
    d = list(map(int, input().split()))

    table = [input().strip() for _ in range(n)]

    free_cells = []

    for i in range(n):
        for j in range(m):
            if table[i][j] == '.':
                free_cells.append((i + 1, j + 1))

    # Assign free cells to people
    for i in range(k):
        if i < len(free_cells):
            r, c = free_cells[i]
            print(r, c)
        else:
            print(0, 0)


solve()
