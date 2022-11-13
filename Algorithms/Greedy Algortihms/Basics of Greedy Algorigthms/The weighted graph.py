# Write your code here
n = int(input())
a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))
print((sum(x ** 2 for x in a) * sum(y ** 2 for y in b) - sum(x * y for x, y in zip(a, b)) ** 2) % 1000000007)
