t = int(input())
for _ in range(t):
    x, y = map(int, input().strip().split())
    print(x if 0 <= y <= x else -1)
