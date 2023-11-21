mod = 1000000007


def fun(N):
    # Your code goes here
    return pow(pow(2, N, mod), 2, mod)


T = int(input())
for _ in range(T):
    N = int(input())
    K = int(input())
    A = map(int, input().split(' '))

    out_ = fun(N)
    print(out_)
