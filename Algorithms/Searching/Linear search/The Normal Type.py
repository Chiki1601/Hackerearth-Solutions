from collections import defaultdict
 
n = int(input())
a = list(map(int, input().strip().split()))
diff = len(set(a))
if diff == 1:
    print(n * (n + 1) // 2)
elif diff == n:
    print(1)
else:
    i = j = res = 0
    distinct = defaultdict(lambda: 0)
    ಠ_ಠ = True
    while j < n:
        if ಠ_ಠ:
            distinct[a[j]] += 1
            if len(distinct) == diff:
                ಠ_ಠ = False
            else:
                j += 1
        else:
            res += n - j
            if distinct[a[i]] > 1:
                distinct[a[i]] -= 1
            else:
                distinct.pop(a[i])
                ಠ_ಠ = True
                j += 1
            i += 1
    print(res)
