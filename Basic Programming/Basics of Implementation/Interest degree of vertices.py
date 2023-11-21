n = int(input())
p = list(map(int, input().strip().split()))
a = list(map(int, input().strip().split()))
print(0 if p.count(1) == 1 else sum(a))
