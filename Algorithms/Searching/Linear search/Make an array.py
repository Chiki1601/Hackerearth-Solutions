def solve(N, A):
    if N == 1:
        return 0 if A[0] == 0 else -1

    total = sum(A)

    if total % (N - 1) != 0:
        return -1

    operations = total // (N - 1)

    if operations < max(A):
        return -1

    return operations
    
T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))

    out_ = solve(N, A)
    print (out_)
