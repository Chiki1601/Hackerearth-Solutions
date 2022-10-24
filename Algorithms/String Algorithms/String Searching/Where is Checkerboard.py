# Write your code here
n, m = map(int, input().strip().split())
a = int('01' * 16, 2)
b = int('10' * 16, 2)
c = int('1' * 32, 2)
s = [0] * m
t = 0
for _ in range(m):
    k = int(input().replace('_', '0').replace('#', '1'), 2)
    i = 0
    while k >= a:
        if s[i] % 2 == 0:
            if (k & c) == a:
                s[i] += 1
            else:
                s[i] = 0
        else:
            if (k & c) == b:
                s[i] += 1
                if s[i] >= 32:
                    t += 1
                    s[i] = 30
            elif (k & c) == a:
                s[i] = 1
            else:
                s[i] = 0
        i += 1
        k >>= 1
print(t)
