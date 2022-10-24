n = int(input())
cell_list = list(map(lambda c: 'WB'.index(c), input().strip().replace('0', 'W')))
 
 
def move(cells, color):
    ln = len(cells)
    dp = [[float('inf')] * 4 for _ in range(ln + 1)]
    dp[0][0] = 0
    for i in range(ln):
        for j in (0, 1):
            for k in (0, 1):
                x = j * 2 + k
                cur = j ^ cells[i]
                if cur == color:
                    dp[i + 1][k * 2] = min(dp[i + 1][k * 2], dp[i][x])
                else:
                    if i + 2 <= ln:
                        y = (1 - k) * 2
                        dp[i + 1][y] = min(dp[i + 1][y], dp[i][x] + 1)
                    if i + 3 <= ln:
                        y = (1 - k) * 2 + 1
                        dp[i + 1][y] = min(dp[i + 1][y], dp[i][x] + 1)
    return min(dp[ln][0], dp[ln][2])
 
 
print(min(move(cell_list, 0), move(cell_list, 1)))
