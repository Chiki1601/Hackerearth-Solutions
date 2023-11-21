t = int(input())
for _ in range(t):
    a = input().strip()
    b = input().strip()
    res = 0
    for i in range(26):
        c1 = a.count(chr(i + 97))
        c2 = b.count(chr(i + 97))
        if c1 != c2:
            if c1 > c2:
                if -1 == res:
                    res = 0
                    break
                res = 1
            elif c1 < c2:
                if 1 == res:
                    res = 0
                    break
                res = -1
    if 1 == res:
        print("You win some.")
    elif -1 == res:
        print("You lose some.")
    elif 0 == res:
        print("You draw some.")
