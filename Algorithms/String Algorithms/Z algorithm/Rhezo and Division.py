# Write your code here
from sys import setrecursionlimit
 
setrecursionlimit(200002)
mod = 1000000007
 
 
def z_function(str1, str2):
    z_text = str1 + '$' + str2
    n = len(z_text)
    z_arr = [0] * n
    left = right = -1
    for i in range(1, n):
        if i > right:
            count = 0
            while i + count < n and z_text[i + count] == z_text[count]:
                count += 1
            z_arr[i] = count
            if count > 1:
                left = i
                right = left + count - 1
        elif left < i <= right:
            k = i - left
            if z_arr[k] < right - i + 1:
                z_arr[i] = z_arr[k]
            else:
                left = i
                count = right - left + 1
                while i + count < n and z_text[i + count] == z_text[count]:
                    count += 1
                z_arr[i] = count
                right = left + count - 1
    return z_arr[len(str1) + 1:]
 
 
def reduce(n):
    p2 = p3 = p5 = p7 = 0
    if n % 8 == 0:
        p2 = 3
    elif n % 4 == 0:
        p2 = 2
    elif n % 2 == 0:
        p2 = 1
    if n % 9 == 0:
        p3 = 2
    elif n % 3 == 0:
        p3 = 1
    if n % 5 == 0:
        p5 = 1
    if n % 7 == 0:
        p7 = 1
    return 2 ** p2 * 3 ** p3 * 5 ** p5 * 7 ** p7
 
 
cache = {}
 
 
def combine(a, idx=-1, val=1):
    if idx >= len(a):
        return 0
    key = (idx, val)
    if key in cache:
        return cache[key]
    # all remaining extensions of this subset will also be divisible by 2520.
    if val % 2520 == 0:
        res = 2 ** (len(a) - (idx + 1))
        cache[key] = res
        return res
    res1 = combine(a, idx + 1, reduce(val)) % mod
    res2 = combine(a, idx + 1, reduce(a[idx] * val)) % mod
    res = (res1 + res2) % mod
    cache[key] = res
    return res
 
 
p = input().strip()
t = input().strip()
z = z_function(p, t)
lp = len(p)
indexes = []
for i in range(len(z)):
    if z[i] == lp:
        indexes.append(i + 1)
print(combine(indexes))
