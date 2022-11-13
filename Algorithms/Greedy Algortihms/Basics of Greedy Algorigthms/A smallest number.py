# Write your code here
t = int(input())
for _ in range(t):
    k = int(input())
    ln = 0
    for i in range(523976):
        if 9 ** i >= k + 8 * i:
            ln = i
            break
    s = '1' * (k - ln)
    if ln == 2:
        for a in range(2, 10):
            for b in range(a, 10):
                if a * b >= k - ln + a + b:
                    s += str(a) + str(b)
                    break
            else:
                continue
            break
    if ln == 3:
        for a in range(2, 10):
            for b in range(a, 10):
                for c in range(b, 10):
                    if a * b * c >= k - ln + a + b + c:
                        s += str(a) + str(b) + str(c)
                        break
                else:
                    continue
                break
            else:
                continue
            break
    if ln == 4:
        for a in range(2, 10):
            for b in range(a, 10):
                for c in range(b, 10):
                    for d in range(c, 10):
                        if a * b * c * d >= k - ln + a + b + c + d:
                            s += str(a) + str(b) + str(c) + str(d)
                            break
                    else:
                        continue
                    break
                else:
                    continue
                break
            else:
                continue
            break
    if ln == 5:
        for a in range(2, 10):
            for b in range(a, 10):
                for c in range(b, 10):
                    for d in range(c, 10):
                        for e in range(d, 10):
                            if a * b * c * d * e >= k - ln + a + b + c + d + e:
                                s += str(a) + str(b) + str(c) + str(d) + str(e)
                                break
                        else:
                            continue
                        break
                    else:
                        continue
                    break
                else:
                    continue
                break
            else:
                continue
            break
    if ln == 6:
        for a in range(2, 10):
            for b in range(a, 10):
                for c in range(b, 10):
                    for d in range(c, 10):
                        for e in range(d, 10):
                            for f in range(e, 10):
                                if a * b * c * d * e * f >= k - ln + a + b + c + d + e + f:
                                    s += str(a) + str(b) + str(c) + str(d) + str(e) + str(f)
                                    break
                            else:
                                continue
                            break
                        else:
                            continue
                        break
                    else:
                        continue
                    break
                else:
                    continue
                break
            else:
                continue
            break
    print(s)
