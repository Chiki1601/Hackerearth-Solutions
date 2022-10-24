# Write your code here
from sys import stdin
 
lines = list(stdin.read().split())
t = int(lines[0])
no = 1
for _ in range(t):
    string = lines[no]
    no += 1
    substring = lines[no]
    no += 1
    ln = len(substring)
    for s in (substring, substring[::-1]):
        i = 0
        for c in string:
            if i == ln:
                break
            if c == s[i]:
                i += 1
        if i < ln:
            print('BAD STRING')
            break
    else:
        print('GOOD STRING')
