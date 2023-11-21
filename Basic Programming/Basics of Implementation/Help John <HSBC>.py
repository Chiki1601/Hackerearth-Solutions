from bisect import bisect

n = int(input())
bag = [int(input())]
print(-1, -1)
for _ in range(n - 1):
    x = int(input())
    if x > bag[-1]:
        print(bag[-1], -1)
        bag.append(x)
    elif x < bag[0]:
        print(-1, bag[0])
        bag.insert(0, x)
    else:
        i = bisect(bag, x)
        print(bag[i - 1], bag[i])
        bag.insert(i, x)
