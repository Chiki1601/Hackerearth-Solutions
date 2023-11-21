t = int(input())
for _ in range(t):
    n = int(input())
    m = bin(n)[2:]
    if not m.count('0'):
        print(n)
    else:
        k = len(m)
        print(2 ** (k - 1) - 1)
