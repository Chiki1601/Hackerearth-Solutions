# Write your code here
t = int(input())
for _ in range(t):
    n = int(input())
    t1 = []
    t2 = []
    for _ in range(n):
        a, b = map(int, input().strip().split())
        t1.append(a)
        t2.append(b)
    t1.sort()
    t2.sort()
    count = 0
    for i in range(n):
        if t1[i] < t2[i - count]:
            count += 1
    print(max(1, count))
