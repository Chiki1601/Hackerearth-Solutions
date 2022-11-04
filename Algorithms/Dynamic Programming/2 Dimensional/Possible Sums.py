  
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    sums = {0}
    for i in a:
        sums.update(i + j for j in sums.copy())
    print(len(sums))
