n = int(input())
characters = list(input())
first = [0] * 26
second = [0] * 26
ord_a = ord('a')
y = n // 2
for x in range(n // 2):
    first[ord(characters[x]) - ord_a] += 1
    second[ord(characters[y]) - ord_a] += 1
    y += 1
 
 
def case_1(a, b):
    list_a = list(a)
    list_b = list(b)
    ans = list_a[0]
    list_a[25] += ans
    list_a[0] = 0
    for i in range(1, 26):
        req = list_a[i]
        for j in range(i):
            if list_b[j] >= req:
                list_b[j] -= req
                req = 0
            else:
                req -= list_b[j]
                list_b[j] = 0
            if req == 0:
                break
        ans += req
    return ans
 
 
def case_2(a, b):
    list_a = list(a)
    list_b = list(b)
    ans = list_a[25]
    list_a[0] += ans
    list_a[25] = 0
    for i in range(24, -1, -1):
        req = list_a[i]
        for j in range(i + 1, 26):
            if list_b[j] >= req:
                list_b[j] -= req
                req = 0
            else:
                req -= list_b[j]
                list_b[j] = 0
            if req == 0:
                break
        ans += req
    return ans
 
 
def case_3(a, b, ln):
    ans = ln
    for i in range(26):
        ans -= 2 * min(a[i], b[i])
    return ans // 2
 
 
c1 = case_1(first, second)
c2 = case_2(first, second)
c3 = case_3(first, second, n)
print(min(c1, c2, c3))
