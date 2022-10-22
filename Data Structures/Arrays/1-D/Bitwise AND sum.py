for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    i=1;last = 2**25 - 1
    p = {d: n for d in range(25)}
    for v in reversed(a[1:]):
        nou_last = last & v
        if nou_last != last:
            b = bin(last - nou_last)
            for d, v in enumerate(str(b)[:1:-1]):
                if v == '1':
                    p[d] = i
            last = nou_last
            if last == 0:
                break
        i += 1
    
    value = sum(v * 1<<k for k, v in p.items())
    ans, primer, i = - (2**25 - 1) + value, 2**25 - 1, n - 1
    canvis = set(p.values())
    canvis.update([0, n - 1])
    for v in a:
        nou_primer = primer & v
        if nou_primer != primer:
            b = bin(primer - nou_primer)
            for d, v in enumerate(str(b)[:1:-1]):
                if v == '1':
                    value -= p[d] * 1<<d
                    p[d] = 0
            primer = nou_primer
            if primer == 0:
                break
        if i in canvis:
            loss = 0
            for k, v in p.items():
                if i < v:
                    loss += 1<<k
        value -= loss
        ans += value
        i -= 1
    
    print(ans)
