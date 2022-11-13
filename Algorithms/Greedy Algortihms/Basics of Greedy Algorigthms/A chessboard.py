# Write your code here
t = int(input())
for _ in range(t):
    x1, y1 = map(int, input().strip().split())
    x2, y2 = map(int, input().strip().split())
    if x1 == x2 and y1 == y2:
        print('SECOND')
    elif max(x1, x2) - min(x1, x2) in (0, 1) and max(y1, y2) - min(y1, y2) in (0, 1):
        print('FIRST')
    else:
        print('DRAW')
