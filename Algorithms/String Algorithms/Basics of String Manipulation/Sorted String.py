from collections import Counter
 
t = int(input())
for _ in range(t):
    s = input()
    counter = Counter(s)
    counter = sorted(counter.items(), key=lambda x: (x[-1], x[0]))
    ans = ''
    for k, v in counter:
        ans += k * v
    print(ans)
