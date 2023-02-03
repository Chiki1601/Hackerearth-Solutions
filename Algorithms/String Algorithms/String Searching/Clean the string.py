from collections import Counter
from itertools import permutations

t = int(input())
ps = tuple(permutations('012'))
for _ in range(t):
    s = input().strip()
    ans = float('inf')
    counter = Counter(s)
    for a, b, c in ps:
        d = counter[a] + counter[b]
        counter_d = Counter(s[counter[a]:d])
        ac = Counter(s[:counter[a]])[c]
        ba = counter_d[a]
        bc = counter_d[c]
        ca = Counter(s[d:])[a]
        ans = min(ans, ac + ba + bc + ca - min(ac, ca))
    print(ans)
