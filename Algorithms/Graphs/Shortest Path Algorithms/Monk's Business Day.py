# Write your code here
t = int(input())
 
 
def bellman_ford(size, edges):
    costs = [float('-inf')] * size
    costs[0] = 0
    for _ in range(size - 1):
        for u, v, w in edges:
            costs[v] = max(costs[v], costs[u] + w)
    for u, v, w in edges:
        if costs[v] < costs[u] + w:
            return True
    return False
 
 
for _ in range(t):
    n, m = map(int, input().strip().split())
    trade = []
    for _ in range(m):
        i, j, c = map(int, input().strip().split())
        i -= 1
        j -= 1
        trade.append((i, j, c))
    print('Yes' if bellman_ford(n, trade) else 'No')
