# Write your code here
from collections import defaultdict
from fractions import Fraction
 
 
def check(start, start_cost, adjacency, seen):
    seen[start] = True
    for neighbor, next_cost in adjacency[start]:
        if neighbor not in visited and next_cost < start_cost:
            check(neighbor, start_cost, adjacency, seen)
 
 
t = int(input())
for _ in range(t):
    # n = int(input())
    # k = int(input())
    n, k = map(int, input().strip().split())
    streets = defaultdict(list)
    for _ in range(k):
        x, y, cst = map(int, input().strip().split())
        streets[x].append((y, cst))
        streets[y].append((x, cst))
    m = int(input())
    a = 0
    for _ in range(m):
        c, d = map(int, input().strip().split())
        cost = 0
        for y, cst in streets[c]:
            if y == d:
                cost = cst
                break
        visited = {}
        check(c, cost, streets, visited)
        if not (c in visited and d in visited):
            a += 1
    if a == m:
        print('1/1')
    else:
        print(Fraction(a, m))
