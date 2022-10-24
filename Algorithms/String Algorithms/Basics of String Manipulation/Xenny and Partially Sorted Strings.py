# Write your code here
t = int(input())
for _ in range(t):
    n, k, m = map(int, input().strip().split())
    a = [input() for _ in range(n)]
    a.sort(key=lambda x: x[:m])
    print(a[k - 1])
