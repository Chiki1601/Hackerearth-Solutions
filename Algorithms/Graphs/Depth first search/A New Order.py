from collections import defaultdict
from heapq import heappush, heappop
 
w = int(input())
words = []
edges = defaultdict(list)
ranks = defaultdict(int)
for i in range(w):
    s = input().strip()
    words.append(s)
    if i:
        prev = words[i - 1]
        j = 0
        k = 0
        lp = len(prev)
        lc = len(s)
        while j < lp and k < lc:
            if prev[j] == s[k]:
                j += 1
                k += 1
            else:
                break
        if j == lp and k == lc:
            continue
        if j == lp:
            j -= 1
        edges[prev[j]].append(s[k])
        ranks[s[k]] += 1
        if prev[j] not in ranks:
            ranks[prev[j]] = 0
heap = []
for k, v in ranks.items():
    heappush(heap, (v, k))
alphabets = []
visited = set()
while heap:
    lvl, letter = heappop(heap)
    same = ''
    while heap:
        if letter not in visited:
            same += letter
        next_lvl, next_letter = heappop(heap)
        letter = next_letter
        if next_lvl != lvl:
            heappush(heap, (next_lvl, next_letter))
            break
    for i in same:
        visited.add(i)
        if i in edges:
            for j in edges[i]:
                ranks[j] -= 1
                heappush(heap, (ranks[j], j))
    if same:
        alphabets.append(same)
other = set()
for s in words:
    for letter in s:
        if letter not in ranks:
            other.add(letter)
other = sorted(other)
if other and alphabets:
    other.extend(list(alphabets[0]))
    other.sort()
    alphabets[0] = ''.join(other)
print(*alphabets, sep='\n')
