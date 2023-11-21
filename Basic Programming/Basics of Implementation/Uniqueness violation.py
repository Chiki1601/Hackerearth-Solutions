def solve(A, U, N):
    # Write your code here
    selected = []
    x = A[0]
    y = U[0]
    for i in range(1, N):
        if y == U[i]:
            x = max(x, A[i])
        else:
            selected.append(x)
            x = A[i]
            y = U[i]
    selected.append(x)
    return sum(selected)


T = int(input())
for _ in range(T):
    N = int(input())
    U = list(map(int, input().split()))
    A = list(map(int, input().split()))

    out_ = solve(A, U, N)
    print(out_)
