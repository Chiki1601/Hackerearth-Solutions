import sys
from collections import Counter
 
n = int(sys.stdin.readline())
y = list(map(int, sys.stdin.readline().strip().split()))
projected = Counter()
for i in y:
    projected[i] += 1
mk = 0  # Monkey King
es = 0  # Earthshaker
wk = []  # Wraith King
qop = []  # Queen of Pain
mc = projected.most_common(2)
if 0 < len(mc):  # find the first highest
    mk = mc[0][1]
for k, v in projected.items():
    if v == mk:
        wk.append(k)
if len(wk) > 1:
    es = mk
    qop = wk
else:
    if 1 < len(mc):  # find the second highest
        es = mc[1][1]
    for k, v in projected.items():
        if v == es:
            qop.append(k)
count = 0
for j in wk:
    for k in qop:
        if j != k:
            temp = 0
            low, high = j, k
            if low > high:
                low, high = high, low
            for i in range(len(y)):
                if y[i] == low or y[i] == high:
                    break
                if low < y[i] < high:
                    temp += 1
                    break
            for i in range(len(y) - 1, -1, -1):
                if y[i] == low or y[i] == high:
                    break
                if low < y[i] < high:
                    temp += 1
                    break
            count = max(count, temp)
print(mk + es + count)
