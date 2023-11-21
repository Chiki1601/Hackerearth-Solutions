n, k = map(int, input().strip().split())
digits = list(map(int, str(n)))
cnt = 0
res = []
for d in digits:
    while cnt < k and res and res[-1] < d:
        res.pop()
        cnt += 1
    res.append(d)
if cnt < k:
    res = res[:len(res) - (k - cnt)]
print(''.join(map(str, res)))
