import sys
import random

input = sys.stdin.readline

N, M = map(int, input().split())

graph = [[] for _ in range(N)]

for _ in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1

    if u != v:
        graph[u].append(v)
        graph[v].append(u)

B = list(map(int, input().split()))
C = list(map(int, input().split()))

profit = [B[i] - C[i] for i in range(N)]


def greedy(order):
    selected = [False] * N
    result = []
    total = 0

    for u in order:
        if profit[u] <= 0:
            continue

        possible = True

        for v in graph[u]:
            if selected[v]:
                possible = False
                break

        if possible:
            selected[u] = True
            result.append(u + 1)
            total += profit[u]

    return total, result


# Strategy 1: highest profit first
order = list(range(N))
order.sort(key=lambda x: profit[x], reverse=True)

best_score, best_result = greedy(order)


# Strategy 2: profit / (degree + 1)
order = list(range(N))
order.sort(
    key=lambda x: profit[x] / (len(graph[x]) + 1),
    reverse=True
)

score, result = greedy(order)

if score > best_score:
    best_score = score
    best_result = result


# A few randomized greedy attempts
random.seed(12345)

for _ in range(10):
    order = list(range(N))
    random.shuffle(order)

    order.sort(
        key=lambda x: (
            profit[x] + random.randint(0, max(1, profit[x] // 10)),
            -len(graph[x])
        ),
        reverse=True
    )

    score, result = greedy(order)

    if score > best_score:
        best_score = score
        best_result = result


# Output
print(len(best_result))
print(*best_result)
