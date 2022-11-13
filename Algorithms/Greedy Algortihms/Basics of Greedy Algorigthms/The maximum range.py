from collections import deque
 
n, k = map(int, input().strip().split())
arr = list(map(int, input().strip().split()))
mxs = deque([0])
mns = deque([0])
last = 0
res = 0
for i in range(1, len(arr)):
    while mxs and arr[i] + k < arr[mxs[0]]:
        last = max(last, mxs.popleft())
    while mns and arr[i] - k > arr[mns[0]]:
        last = max(last, mns.popleft())
    res = max(res, i - last)
    while mxs and arr[mxs[-1]] <= arr[i]:
        mxs.pop()
    while mns and arr[mns[-1]] >= arr[i]:
        mns.pop()
    mns.append(i)
    mxs.append(i)
print(res)
