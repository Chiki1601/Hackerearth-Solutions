# Write your code here
t = int(input())
for i in range(t):
    s = input()
    ln = len(s)
    if ln == 1:
        print(s)
    else:
        print(s[ln - 2::-2] + s[1 - ln % 2::2])
