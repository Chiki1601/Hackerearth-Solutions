from collections import deque
 
 
def find(x, par):
    if x == par[x]:
        return x
    par[x] = find(par[x], par)
    return par[x]
 
 
def union(x, y, par, cnt):
    x = find(x, par)
    y = find(y, par)
    if len(cnt[x]) < len(cnt[y]):
        x, y = y, x
    par[y] = x
    res = 0
    for i, val in cnt[y].items():
        if i in cnt[x]:
            res += cnt[x][i] * val
            cnt[x][i] += val
        else:
            cnt[x][i] = val
    return res
 
 
n = int(input())
edges = [list(map(lambda x: int(x) - 1, input().strip().split())) for _ in range(n - 1)]
c = list(map(int, input().strip().split()))
d = list(map(int, input().strip().split()))
parents = [i for i in range(n)]
counter = [{i: 1} for i in c]
disconnected = deque([])
for i in d[::-1]:
    disconnected.appendleft(
        union(
            edges[i - 1][0],
            edges[i - 1][-1],
            parents,
            counter,
        )
    )
print(*disconnected, sep='\n')
