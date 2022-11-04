# Write your code here
t = int(input())
for _ in range(t):
    n, k = map(int, input().strip().split())
    arr = list(map(int, input().strip().split()))
    sn = n * (n + 1) // 2
    total = sum(arr)
    op_1 = sum(map(lambda x: -x, arr))
    op_2 = total + sn
    op_3 = total - sn
    if op_1 < k < min(op_2, op_3) and op_2 > 250:
        print('YES')
    elif k > op_2 or k < op_3:
        print('NO')
    else:
        print('YES')
