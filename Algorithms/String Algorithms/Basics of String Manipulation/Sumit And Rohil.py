from collections import defaultdict
 
n = int(input())
groups = defaultdict(list)
for _ in range(n):
    s = input().strip()
    groups[s[0] + s[-1]].append(''.join(sorted(s)))
count = 0
for val in groups.values():
    count += len(set(val))
print(count)
