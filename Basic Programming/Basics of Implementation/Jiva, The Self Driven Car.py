from sys import stdin

t = int(stdin.readline())
for _ in range(t):
    n, m = map(int, stdin.readline().strip().split())
    passengers = []
    for _ in range(n):
        s, e = map(int, stdin.readline().strip().split())
        passengers.append((s, e))
    passengers = sorted(passengers, key=lambda x: x[0])
    counter = [0] * 101
    for i in range(n):
        s, e = map(lambda x: x + 1, passengers[i])
        if counter[s] >= m:
            continue
        for j in range(s, e):
            counter[j] += 1
    is_full = 0 == m
    revenue = 0
    for i in range(1, 101):
        if counter[i]:
            if 2 == counter[i]:
                revenue += 10 * counter[i] * 0.95
            elif 3 <= counter[i]:
                revenue += 10 * counter[i] * 0.93
            else:
                revenue += 10 * counter[i]
        is_full = is_full or counter[i] == m
    if is_full:
        print(round(revenue), 'Cab was full')
    else:
        print(round(revenue))
