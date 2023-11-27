from collections import Counter


def solve(n, arr):
    # Write your code here
    counter = Counter(arr)
    chocolates = sorted((k for k, v in counter.items() if v == 1), reverse=True)
    alice = sum(chocolates[::2])
    bob = sum(chocolates[1::2])
    return "Alex" if alice > bob else "Bob"


T = int(input())
for _ in range(T):
    n = int(input())
    arr = list(map(int, input().split()))

    out_ = solve(n, arr)
    print(out_)
