import sys
 
 
def comparison(arr1, arr2, start=0, end=None):
    if end is None:
        end = min(len(arr1), len(arr2))
    for i in range(start, end):
        if arr1[i] == '1' and arr2[i] == '0':
            return i
        elif arr1[i] == '0' and arr2[i] == '1':
            return -i
    return 0
 
 
n, q = map(int, sys.stdin.readline().strip().split())
a = list(sys.stdin.readline())
b = list(sys.stdin.readline())
begin = 0
for i in map(int, sys.stdin.readlines()):
    b[i - 1] = '1'
    index = comparison(a, b, begin, n)
    if index <= 0:
        print('YES')
    else:
        begin = index
        print('NO')
