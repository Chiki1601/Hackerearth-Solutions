# Write your code here
a = input().strip()
b = input().strip()
lna = len(a)
lnb = len(b)
if lna == lnb:
    for i in range(lna):
        if a[i] > b[i]:
            print('NO')
            break
    else:
        print('YES')
else:
    print('NO')
