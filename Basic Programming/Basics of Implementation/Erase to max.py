from collections import Counter


def getResult(Arr):
    # Write your code here
    counter = Counter(Arr)
    op = [k * v for k, v in counter.items()]
    op.remove(min(op))
    return sum(op)


T = int(input())
for _ in range(T):
    N = int(input())
    Arr = list(map(int, input().split()))

    out_ = getResult(Arr)
    print(out_)
