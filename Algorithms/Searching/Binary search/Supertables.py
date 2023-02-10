import math
 
t = int(input())
for _ in range(t):
    a, b, n = map(int, input().strip().split())
    res = -1
    lcm = (a * b) // (math.gcd(a, b))
    low, high = 1, 1000000000000  # x / 1000 >= 1000000000; 1000 - A, B; 1000000000 - N
    while low <= high:
        mid = (low + high) // 2
        x = mid // a + mid // b - mid // lcm
        if x < n:
            low = mid + 1
        else:
            res = mid
            high = mid - 1
    print(res)
