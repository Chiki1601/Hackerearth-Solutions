# Write your code here
t = int(input())
for _ in range(t):
    n = int(input())
    p = map(int, input().strip().split())
    print(sum(set(p)))
