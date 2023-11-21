from string import ascii_lowercase

s = input().strip()
t = input().strip()
u = s + t
counter = {}
for i in ascii_lowercase:
    counter[i] = u.count(i)
more = length = 0
for i in counter.values():
    if i % 2:
        length += i - 1
        more = 1
    else:
        length += i
length += more
print(length)
