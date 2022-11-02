# Write your code here
from collections import defaultdict
 
COLORS_SHIRT = {
    'PINK': 'P',
    'BLUE': 'B',
}
 
GENDER = {
    'BOY': 'B',
    'GIRL': 'G',
}
 
 
def inversions(x, color, adjacency, seen, colors):
    if seen[x]:
        return False
    colors[x] = color
    seen[x] = True
    for y in adjacency[x]:
        if y != x:
            if seen[y]:
                if colors[y] == color:
                    return True
            else:
                new_color = COLORS_SHIRT['BLUE']
                if color == COLORS_SHIRT['BLUE']:
                    new_color = COLORS_SHIRT['PINK']
                colors[y] = new_color
                if inversions(y, new_color, adjacency, seen, colors):
                    return True
    return False
 
 
n, m = map(int, input().strip().split())
students = list(input().strip().split())
friends = defaultdict(set)
for _ in range(m):
    u, v = map(lambda x: int(x) - 1, input().strip().split())
    friends[u].add(v)
    friends[v].add(u)
wears = [0] * n
impossible = inversions(0, COLORS_SHIRT['PINK'], friends, [False] * n, wears)
if impossible:
    print('Not possible')
else:
    inversions1 = inversions2 = 0
    for i in range(n):
        if (students[i] == GENDER['BOY'] and wears[i] == COLORS_SHIRT['PINK']) or (
                students[i] == GENDER['GIRL'] and wears[i] == COLORS_SHIRT['BLUE']):
            inversions1 += 1
    wears = [0] * n
    inversions(0, COLORS_SHIRT['BLUE'], friends, [False] * n, wears)
    for i in range(n):
        if (students[i] == GENDER['BOY'] and wears[i] == COLORS_SHIRT['PINK']) or (
                students[i] == GENDER['GIRL'] and wears[i] == COLORS_SHIRT['BLUE']):
            inversions2 += 1
    print(min(inversions1, inversions2))
