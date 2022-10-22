from collections import defaultdict
 
n, m = map(int, input().strip().split())
a = list(map(int, input().strip().split()))
subsets = defaultdict(list)
for i in a:
    subsets[i % m].append(i)
supreme_subset = []
for subset in subsets.values():
    if len(subset) > len(supreme_subset):
        supreme_subset = sorted(subset)
    elif len(subset) == len(supreme_subset):
        supreme_subset = min(supreme_subset, sorted(subset))
print(len(supreme_subset))
print(*supreme_subset)
