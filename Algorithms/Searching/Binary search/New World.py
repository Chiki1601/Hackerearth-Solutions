# Write your code here
import bisect
 
 
def check(arr, x, ln, val):
    count = 0
    i = 0
    while i < ln - 1:
        index = bisect.bisect(arr, arr[i] + x) - 1
        if index > i:
            i = index
            count += 1
        else:
            return False
    return count <= val
 
 
t = int(input())
for _ in range(t):
    n, k = map(int, input().strip().split())
    stones = list(map(int, input().strip().split()))
    low = 1
    high = stones[-1] - stones[0]  # Location of all stones are given in ascending order.
    while low <= high:
        mid = (low + high) // 2
        if check(stones, mid, n, k):
            high = mid - 1
        else:
            low = mid + 1
    print(low)
