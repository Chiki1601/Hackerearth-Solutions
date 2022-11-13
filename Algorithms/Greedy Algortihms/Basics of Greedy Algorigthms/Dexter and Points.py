n = int(input())
a = map(int, input().split())
num = 1
for i in a:
    num = num * ((pow(i + 1, 2) + 1) // 2) % 1000000007
print(num)
