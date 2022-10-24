# Write your code here
q = int(input())
s = input().strip()
vector = [0] * (len(s) + 1)
for i, c in enumerate(s, 1):
    vector[i] = vector[i - 1] ^ 1 << (ord(c) - 97)  # ord('a') = 97
for _ in range(q):
    l, r = map(int, input().split())
    val = vector[r] ^ vector[l - 1]
    if val & (val - 1):
        print('Impossible')
    else:
        print('Possible')
