# Write your code here
n = int(input())
a = list(map(int, input().strip().split()))
d = 1
q = int(input())
for _ in range(q):
    d *= int(input())
print(*(i // d for i in a))
