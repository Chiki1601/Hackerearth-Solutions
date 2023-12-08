t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    total = sum(a)
    if total % 2:
        print(total)
    else:
        min_odd = float("inf")
        for i in a:
            if i % 2 and i < min_odd:
                min_odd = i
        print(total - min_odd if min_odd != float("inf") else 0)
