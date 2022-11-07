n = int(input())
a = list(map(int, input().strip().split()))
if a == sorted(a):
    print(n * (n + 1))
else:
    print(n * (n + 1) // 2)
