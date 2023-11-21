def find_the_winner(A):
    # Write your code here
    if len(set(A)) % 2:
        return 'P'
    else:
        return 'Q'


T = int(input())
for _ in range(T):
    n = int(input())
    A = map(int, input().split())

    out_ = find_the_winner(A)
    print(out_)
