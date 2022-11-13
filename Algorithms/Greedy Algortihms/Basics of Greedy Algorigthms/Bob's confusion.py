t = int(input())
for _ in range(t):
    c = [list(map(int, input().strip().split())) for _ in range(3)]
    ans = 'YES'
    for i in range(1, 3):
        diff = c[i][0] - c[0][0]
        for j in range(1, 3):
            sub = c[i][j] - c[0][j]
            if sub != diff:
                ans = 'NO'
                break
        else:
            continue
        break
    print(ans)
