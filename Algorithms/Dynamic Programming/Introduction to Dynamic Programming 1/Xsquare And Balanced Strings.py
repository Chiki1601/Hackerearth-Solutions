# Write your code here
t = int(input())
for _ in range(t):
    s = input()
    for c in set(s):
        if s.count(c) % 2:
            print(-1)
            break
    else:
        print(1)
