# Write your code here
t = int(input())
for _ in range(t):
    e = int(input())
    cities = set()
    for _ in range(e):
        x, y = map(int, input().strip().split())
        cities.add(x)
        cities.add(y)
    print(len(cities))
