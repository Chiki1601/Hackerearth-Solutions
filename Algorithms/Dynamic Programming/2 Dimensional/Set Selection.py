n = int(input())
elements = list(map(int, input().strip().split()))
subset = set()
for i in elements:
    temp = {i}
    for j in subset:
        temp.add(j)
        temp.add(j + i)
    subset = temp
t = int(input())
for _ in range(t):
    z = int(input())
    print('Yes' if z in subset else 'No')
