from collections import defaultdict
 
t = int(input())
for _ in range(t):
    n, p = map(int, input().strip().split())
    amounts = defaultdict(int)
    amounts[0] = 0
    for _ in range(n):
        x, y = map(int, input().strip().split())
        for i in sorted(amounts, reverse=True):
            j = i + y
            if j <= p:
                amounts[j] = max(amounts[j], amounts[i] + x - y)
    mx = max(amounts.values())
    a = min(i for i in amounts if amounts[i] == mx)
    print(a, mx + p)
