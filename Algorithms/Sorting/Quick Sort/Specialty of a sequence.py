n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
print(sum(a[:n - k]))
