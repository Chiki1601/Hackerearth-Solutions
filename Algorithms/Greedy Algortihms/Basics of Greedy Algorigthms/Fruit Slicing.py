def solve(N, A):
    # Write your code here
    return len(set(A))


T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))

    out_ = solve(N, A)
    print(out_)
