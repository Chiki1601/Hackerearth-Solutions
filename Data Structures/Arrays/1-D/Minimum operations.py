n = int(input())
a = input().strip().split()
x = 1
for i in range(len(a) - 1):
    if a[i] != a[i + 1]:
        x += 1
print(x)
