# Write your code here
n, m, k = map(int, input().strip().split())
roads = []
for _ in range(m):
    a, b, c = map(int, input().strip().split())
    roads.append((a, b, c))
roads.sort(key=lambda x: x[-1])
 
 
def find(x, p):
    if p[x] != 0:
        return find(p[x], p)
    return x
 
 
parents = [0] * (n + 1)
ranks = [0] * (n + 1)
count = 0
costs = []
for a, b, c in roads:
    pa = find(a, parents)
    pb = find(b, parents)
    if pa != pb:
        costs.append(c)
        count += 1
        if ranks[pa] < ranks[pb]:
            parents[pa] = pb
        elif ranks[pa] > ranks[pb]:
            parents[pb] = pa
        else:
            parents[pb] = pa
            ranks[pa] += 1
    if count == n - 1:
        break
costs.reverse()
ans = -1
if count == n - 1:
    total = sum(costs)
    for i in range(n - 1):
        if total > k:
            total -= costs[i] - 1
        else:
            ans = i
            break
    else:
        if total <= k:
            ans = n - 1
print(ans)
