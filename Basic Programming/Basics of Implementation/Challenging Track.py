t = int(input())
for _ in range(t):
    n, p = map(int, input().strip().split())
    h = list(map(int, input().strip().split()))
    p -= max(0, h[0])
    if p < 0:
        print('No')
        continue
    i = 1
    for i in range(1, n):
        p -= max(0, h[i] - i + h[i] % 2)
        if p < 0:
            print('No')
            break
    else:
        print('Yes', p)
