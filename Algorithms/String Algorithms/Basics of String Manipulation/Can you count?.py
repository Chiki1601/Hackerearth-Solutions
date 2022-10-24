# Write your code here
t = int(input())
vowels = 'aeiou'
for _ in range(t):
    s = input().strip()
    t = ''
    total = 1
    for c in s:
        if c in vowels:
            if c not in t:
                t += c
        elif c == '_':
            total *= len(t)
    print(total % 9223372036854775808)
