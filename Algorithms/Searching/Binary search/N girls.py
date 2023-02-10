# Write your code here
n, k, p, q = map(int, input().strip().split())
a = sorted(map(int, input().strip().split()))
max_len = 1
curr_len = 1
left = 0
right = 1
while right <= n - 1:
    if q * a[right] <= p * a[left]:
        curr_len += 1
        right = right + 1
    else:
        max_len = max(max_len, curr_len)
        left = left + 1
        while left < right and q * a[right] > p * a[left]:
            left = left + 1
        curr_len = right - left + 1
        right = right + 1
else:
    max_len = max(max_len, curr_len)
print(min(max_len + k, n))
