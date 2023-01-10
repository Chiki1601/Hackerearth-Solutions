# Write your code here
from collections import defaultdict
 
 
def check_ew(d, x1, y1, x2, y2):
    if y1 == y2 and x1 < x2:
        d[(x2 - x1) / 2].append((x1, y1, x2, y2))
 
 
def check_ns(d, x1, y1, x2, y2):
    if x1 == x2 and y1 < y2:
        d[(y2 - y1) / 2].append((x1, y1, x2, y2))
 
 
def check_en(d, x1, y1, x2, y2):
    if x2 > x1 and x2 - x1 == y1 - y2:
        d[x2 - x1].append((x1, y1, x2, y2))
 
 
def check_es(d, x1, y1, x2, y2):
    if x2 > x1 and x2 - x1 == y2 - y1:
        d[x2 - x1].append((x1, y1, x2, y2))
 
 
def check_wn(d, x1, y1, x2, y2):
    if x1 > x2 and x1 - x2 == y1 - y2:
        d[x1 - x2].append((x1, y1, x2, y2))
 
 
def check_ws(d, x1, y1, x2, y2):
    if x1 > x2 and x1 - x2 == y2 - y1:
        d[x1 - x2].append((x1, y1, x2, y2))
 
 
t = int(input())
for _ in range(t):
    n = int(input())
    criminals = []
    t = defaultdict(list)  # key: time, value: list of criminals
    for _ in range(n):
        x, y, z = input().split()
        criminals.append((z, float(x), float(y)))
 
    for i in range(n - 1):
        c1 = criminals[i]  # criminal i
        c1_d = c1[0]  # direction of criminal i
        for j in range(i + 1, n):
            c2 = criminals[j]  # criminal j
            c2_d = c2[0]  # direction of criminal j
            if c1_d == 'E' and c2_d == 'W':
                check_ew(t, c1[1], c1[2], c2[1], c2[2])
            if c1_d == 'W' and c2_d == 'E':
                check_ew(t, c2[1], c2[2], c1[1], c1[2])
 
            if c1_d == 'N' and c2_d == 'S':
                check_ns(t, c1[1], c1[2], c2[1], c2[2])
            if c1_d == 'S' and c2_d == 'N':
                check_ns(t, c2[1], c2[2], c1[1], c1[2])
 
            if c1_d == 'E' and c2_d == 'N':
                check_en(t, c1[1], c1[2], c2[1], c2[2])
            if c1_d == 'E' and c2_d == 'S':
                check_es(t, c1[1], c1[2], c2[1], c2[2])
            if c1_d == 'W' and c2_d == 'N':
                check_wn(t, c1[1], c1[2], c2[1], c2[2])
            if c1_d == 'W' and c2_d == 'S':
                check_ws(t, c1[1], c1[2], c2[1], c2[2])
 
            if c1_d == 'N' and c2_d == 'E':
                check_en(t, c2[1], c2[2], c1[1], c1[2])
            if c1_d == 'S' and c2_d == 'E':
                check_es(t, c2[1], c2[2], c1[1], c1[2])
            if c1_d == 'N' and c2_d == 'W':
                check_wn(t, c2[1], c2[2], c1[1], c1[2])
            if c1_d == 'S' and c2_d == 'W':
                check_ws(t, c2[1], c2[2], c1[1], c1[2])
 
    vanish = set()
    for time in sorted(t.keys()):
        new_vanish = set()
        for x1, y1, x2, y2 in t[time]:
            if (x1, y1) not in vanish and (x2, y2) not in vanish:
                new_vanish.add((x1, y1))
                new_vanish.add((x2, y2))
        vanish |= new_vanish
    print(n - len(vanish))
