t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    x = -1
    y = 0
    for i in a:
        x &= i
        y |= i
    x = bin(x).replace('0b', '').count('1')
    y = bin(y).replace('0b', '').count('1')
    print(1 << y - x)
