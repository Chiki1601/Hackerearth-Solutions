t = int(input())
for _ in range(t):
    a = input()
    b = input()
    error = 0
    multi = 10
    for i in range(-1, (len(str(min(int(a), int(b)))) + 1) * -1, -1):
        if int(a[i]) + int(b[i]) >= 10:
            error += multi
        multi *= 10
    print(error)
