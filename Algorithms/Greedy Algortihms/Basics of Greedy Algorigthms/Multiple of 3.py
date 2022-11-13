t = int(input())
for _ in range(t):
    n = input()
    digits = list(map(int, n))
    s = sum(digits)
    if not s % 3:
        print(n)
    else:
        x = s // 3 * 3 + 3 - s
        idx = None
        for i in range(len(n)):
            if digits[i] > x:
                idx = i - 1
                break
            idx = i + 1
        if idx == -1:
            n = str(x) + n
        else:
            n = n[:idx + 1] + str(x) + n[idx + 1:]
        print(n)
