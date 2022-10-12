n = int(input())
a = list(map(int, input().strip().split()))
ln = len(set(a))
res = ln * (ln - 1) // 2
print(res)
