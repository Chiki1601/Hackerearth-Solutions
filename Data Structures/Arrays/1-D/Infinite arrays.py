from itertools import accumulate
 
 
def solve(A, R, L):
    # write your code here
    n = len(A)
    sums = list(accumulate(A, initial=0))
    last = sums[-1]
    for i in range(len(L)):
        left = L[i] - 1
        x = (left // n) * last + sums[left % n]
        right = R[i]
        y = (right // n) * last + sums[right % n]
        yield (y - x) % 1000000007
 
 
T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().strip().split()))
    Q = int(input())
    L = list(map(int, input().strip().split()))
    R = list(map(int, input().strip().split()))
 
    out_ = solve(A, R, L)
    print(' '.join(map(str, out_)))
