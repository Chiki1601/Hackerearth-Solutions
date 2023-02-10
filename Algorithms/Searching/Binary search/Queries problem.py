# Write your code here
import math
import sys
 
n, q = map(int, sys.stdin.readline().strip().split())
a = map(int, sys.stdin.readline().strip().split())
arr = list(map(math.log, a))
left = 0
right = n - 1
left_sum = right_sum = 0
while left <= right:
    if left_sum < right_sum:
        left_sum += arr[left]
        left += 1
    else:
        right_sum += arr[right]
        right -= 1
changed = False
i = 0
if left:
    i = left - 1
for _ in range(q):
    q_type = list(map(int, sys.stdin.readline().strip().split()))
    if q_type[0] == 1 and q_type[2] != 1:
        pos = q_type[1]
        val = math.log(q_type[2])
        if pos - 1 > i:
            right_sum += val
        else:
            left_sum += val
        arr[pos - 1] += val
        changed = True
    else:
        if changed:
            if left_sum >= right_sum:
                while i > 1:
                    new_left_sum = left_sum - arr[i]
                    new_right_sum = right_sum + arr[i]
                    if abs(new_left_sum - new_right_sum) > abs(left_sum - right_sum):
                        break
                    left_sum, right_sum = new_left_sum, new_right_sum
                    i -= 1
            else:
                while i < n - 2:
                    new_left_sum = left_sum + arr[i + 1]
                    new_right_sum = right_sum - arr[i + 1]
                    if abs(new_left_sum - new_right_sum) >= abs(left_sum - right_sum):
                        break
                    left_sum, right_sum = new_left_sum, new_right_sum
                    i += 1
            changed = False
        print(i + 1)
