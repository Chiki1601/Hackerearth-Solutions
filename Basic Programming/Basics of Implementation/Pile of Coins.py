t = int(input())
for _ in range(t):
    p, q = map(int, input().strip().split())
    if p % 2 and q % 2:
        print('Jeel')
    else:
        print('Ashish')
