t = int(input())
for _ in range(t):
    n = int(input())
    abcd = list(map(int, input().strip().split()))
    print(max((n + i - 1) // i for i in abcd) + 3)
