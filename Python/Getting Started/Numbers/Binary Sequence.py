from sys import stdin
 
t = int(stdin.readline())
for _ in range(t):
    x, y, a, b = map(int, stdin.readline().strip().split())
    if x * y == a + b:
        print('Yes')
    else:
        print('No')
