from collections import defaultdict
 
 
def fill_subtrees(sub, values, adj, cur, cache):
    if len(adj[cur]) == 0:
        cache[cur - 1] = True
        sub[cur][values[cur - 1]] = 1
        return
    sub[cur][values[cur - 1]] = 1
    for i in adj[cur]:
        if i not in sub and not cache[cur - 1]:
            fill_subtrees(sub, values, adj, i, cache)
        if not cache[cur - 1]:
            for j in sub[i]:
                sub[cur][j] = sub[cur].get(j, 0) + sub[i][j]
    cache[cur - 1] = True
    return
 
 
def get_lower_bound(arr, key, start, end):
    if start > end:
        return -1
    if key < arr[0]:
        return -1
    if key >= arr[-1]:
        return end
    if start == end:
        return start
    mid = (start + end) // 2
    if arr[mid] <= key < arr[mid + 1]:
        return mid
    if key < arr[mid]:
        return get_lower_bound(arr, key, start, mid - 1)
    return get_lower_bound(arr, key, mid + 1, end)
 
 
def get_upper_bound(arr, key, start, end):
    if start > end:
        return -1
    if key > arr[-1]:
        return -1
    if key <= arr[0]:
        return 0
    if start == end:
        return start
    mid = (start + end) // 2
    if arr[mid] >= key > arr[mid - 1]:
        return mid
    if key < arr[mid]:
        return get_upper_bound(arr, key, start, mid - 1)
    return get_upper_bound(arr, key, mid + 1, end)
 
 
n, q = map(int, input().strip().split())
trees = defaultdict(list)
subtrees = defaultdict(dict)
for _ in range(n - 1):
    a, b = map(int, input().strip().split())
    trees[a].append(b)
    trees[b].append(a)
p = tuple(map(int, input().strip().split()))
for i in range(1, n + 1):
    for j in trees[i]:
        trees[j].remove(i)
visited = [False] * n
fill_subtrees(subtrees, p, trees, 1, visited)
final = defaultdict(list)
length = defaultdict(int)
for i in subtrees:
    for j in subtrees[i]:
        final[i].append(subtrees[i][j])
        length[i] += 1
    final[i].sort()
for _ in range(q):
    u, l, r = map(int, input().strip().split())
    right = get_lower_bound(final[u], r, 0, length[u] - 1)
    left = get_upper_bound(final[u], l, 0, length[u] - 1)
    if right == -1 or left == -1:
        ans = 0
    else:
        ans = right - left + 1
    print(ans)
