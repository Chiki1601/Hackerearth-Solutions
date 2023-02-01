from collections import Counter

t = int(input())
for _ in range(t):
    s = input()
    ans = 1
    c = Counter(s).values()
    for i in c:
        ans *= i
    print(ans % 1000000007)
