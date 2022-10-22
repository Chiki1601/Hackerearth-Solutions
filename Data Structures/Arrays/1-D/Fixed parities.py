n = int(input())
a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))
q = int(input())
for _ in range(q):
    r1, c1 = map(int, input().strip().split())
    r2, c2 = map(int, input().strip().split())
    if (a[r1 - 1] + b[c1 - 1]) % 2 == (a[r2 - 1] + b[c2 - 1]) % 2:
        print('YES')
    else:
        print('NO')
