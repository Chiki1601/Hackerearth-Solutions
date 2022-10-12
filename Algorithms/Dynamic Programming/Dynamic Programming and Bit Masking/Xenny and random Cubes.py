from functools import lru_cache
 
 
@lru_cache(maxsize=None)
def find_out(ith=0, chosen=0):
    count = 0
    if ith == k:
        return 1
    for i in range(n):
        if not (chosen & (1 << i)):
            chosen |= 1 << i
            x = 0
            for j in faces[i]:
                if j == s[ith]:
                    x += 1
            if x:
                count += x * find_out(ith + 1, chosen)
            chosen -= 1 << i
    return count
 
 
n, k = map(int, input().strip().split())
faces = []
for _ in range(n):
    faces.append(input().strip().split())
s = input().strip()
print(find_out() % 1000000007)
