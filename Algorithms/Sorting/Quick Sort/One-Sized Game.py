# Write your code here
import bisect
import math
 
NUM_BUCKETS = 10
 
 
def insert_idx(buckets, idx):
    bucket = hash(idx) % NUM_BUCKETS
    bisect.insort_right(buckets[bucket], idx)
 
 
def get_adjusted_weight(indices, idx):
    """
    adjusted weight is idx - count of number of indices that are less than idx. (+1)
    """
    count = 0
    for i in range(NUM_BUCKETS):
        count += bisect.bisect_right(indices[i], idx)
    return idx - count + 1
 
 
t = int(input())
for _ in range(t):
    n = input()
    arr = list(map(int, input().strip().split()))
    aug_a = [(v, k) for k, v in enumerate(arr)]
    aug_a.sort()
    removed_indices = {k: [] for k in range(NUM_BUCKETS)}
    delta = 0
    i = 0
    ln = len(aug_a)
    while i < ln:
        weight = get_adjusted_weight(removed_indices, aug_a[i][1])
        num_chunks = int(math.ceil((aug_a[i][0] - delta + 1) / weight))
        delta += num_chunks * weight
        while i < ln and delta > aug_a[i][0]:
            insert_idx(removed_indices, aug_a[i][1])
            i += 1
        if i == ln - 1:
            print('Ladia')
            break
    else:
        print('Kushagra')
