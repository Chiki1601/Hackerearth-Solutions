from math import gcd


def define_special_numbers(mx, vals, x=0):
    if x > mx:
        return
    if x > 0:
        vals.append(x)
    define_special_numbers(mx, vals, 10 * x + 4)
    define_special_numbers(mx, vals, 10 * x + 7)


n = int(input())
special_numbers = []
define_special_numbers(n, special_numbers)
count = k = 0
for i in special_numbers:
    k += 1
    for j in special_numbers[k:]:
        if gcd(i, j) == 1:
            count += 1
print(count)
