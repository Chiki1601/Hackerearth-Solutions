t = int(input())
 
 
def init(s):
    temp = [0] * 26
    for c in s:
        temp[ord(c) - 97] += 1  # 97 is ord('a')
    return tuple(temp)
 
 
def add(row_a, row_b):
    temp = [0] * 26
    for i in range(26):
        temp[i] = row_a[i] + row_b[i]
    return tuple(temp)
 
 
def subtract(row_a, row_b):
    temp = [0] * 26
    for i in range(26):
        temp[i] = row_a[i] - row_b[i]
    return tuple(temp)
 
 
def formed(matrix):
    temp = [tuple([0] * 26)]
    for y in matrix:
        for i in range(len(temp)):
            temp.append(add(temp[i], y))
    return temp
 
 
for _ in range(t):
    n = int(input())
    strings_matrix = [init(input()) for _ in range(n)]
    sleep_matrix = init(input())
    m = (n + 1) // 2
    first_form = set(formed(strings_matrix[:m]))
    if sleep_matrix in first_form:
        print('YES')
    else:
        second_formed = formed(strings_matrix[m:])
        for x in second_formed:
            if subtract(sleep_matrix, x) in first_form:
                print('YES')
                break
        else:
            print('NO')
