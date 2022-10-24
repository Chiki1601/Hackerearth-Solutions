t = int(input())
for _ in range(t):
    s = input()
    n1 = len(s)
    n2 = len(set(s))
    if (n2 >= 4 or n1 >= 10) or (n2 == 3 and n1 >= 5) or (n2 == 2 and n1 >= 7):
        print('YES')
    else:
        print('NO')
