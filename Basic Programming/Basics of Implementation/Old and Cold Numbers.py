from itertools import accumulate
from sys import stdin


def is_old(x):
    x = int(x)
    if x % sum(divmod(x, 2)):
        return 0
    return 1


t = int(stdin.readline())
for _ in range(t):
    n = int(stdin.readline())
    a = list(accumulate([0] + list(map(is_old, stdin.readline().strip().split()))))
    q = int(stdin.readline())
    for tc in range(q):
        l, r = map(int, stdin.readline().strip().split())
        o = a[r] - a[l - 1]
        c = r - l + 1 - o
        if c > o:
            print((c - o + 1) // 2)
        else:
            print(0)
