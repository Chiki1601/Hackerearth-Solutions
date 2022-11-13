n, m = map(int, input().strip().split())
boxes = [0] * m
for _ in range(n):
    p, b = map(int, input().strip().split())
    boxes[b - 1] = max(p, boxes[b - 1])
print(sum(boxes))
