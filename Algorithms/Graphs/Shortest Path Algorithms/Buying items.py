# Write your code here
n, m = map(int, input().strip().split())
matrix = [[] for _ in range(n)]
for _ in range(m):
    *objects, c = map(int, input().strip().split())
    for i in range(n):
        if objects[i] == 1:
            matrix[i].append((c, set(j for j in range(n) if objects[j] == 1)))
 
 
def buy_objects(cost, mat, obj_idx, size, buy_objs, cache=None):
    if cache is None:
        cache = {}
    if len(buy_objs) == size:
        return cost
    val = float('inf')
    if obj_idx == size:
        return val
    key = '-'.join(str(x) for x in sorted(list(buy_objs))) + '-' + str(obj_idx)
    if key in cache:
        return cost + cache[key]
    if obj_idx in buy_objs:
        val = min(val, buy_objects(0, mat, obj_idx + 1, size, buy_objs, cache))
    else:
        for price, sell_objs in mat[obj_idx]:
            val = min(val, buy_objects(price, mat, obj_idx + 1, size, buy_objs | sell_objs, cache))
    cache[key] = val
    return cost + val
 
 
print(buy_objects(0, matrix, 0, n, set()))
