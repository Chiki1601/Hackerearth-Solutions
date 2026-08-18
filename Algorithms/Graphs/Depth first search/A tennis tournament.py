import sys

input = sys.stdin.buffer.readline

n, m = map(int, input().split())

g = [[] for _ in range(n)]
edges = []

for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1

    g[u].append(v)
    edges.append((u, v))


# ---------------------------------------------------------
# 1. Check for a cycle of length 2
#
# u -> v
# v -> u
# ---------------------------------------------------------

edge_set = set()

for u, v in edges:
    if (v, u) in edge_set:
        print(2)
        print(u + 1, v + 1)
        print(v + 1, u + 1)
        sys.exit(0)

    edge_set.add((u, v))


# ---------------------------------------------------------
# 2. Try to find a cycle of length 3
#
# u -> v -> w -> u
#
# Use sets for adjacency lookup.
# ---------------------------------------------------------

adj = [set() for _ in range(n)]

for u, v in edges:
    adj[u].add(v)


# To reduce work, iterate over the smaller degree side.
for u in range(n):

    # For every u -> v
    for v in g[u]:

        # Check v -> w and w -> u
        for w in g[v]:

            if w == u:
                continue

            if u in adj[w]:
                print(3)
                print(u + 1, v + 1)
                print(v + 1, w + 1)
                print(w + 1, u + 1)
                sys.exit(0)


# ---------------------------------------------------------
# 3. No 2/3 cycle found.
#
# Find ANY directed cycle using iterative DFS.
#
# This is important for the approximate/scoring nature
# of the problem: returning a valid cycle is much better
# than returning -1.
# ---------------------------------------------------------

state = [0] * n
parent = [-1] * n

# state:
# 0 = unvisited
# 1 = currently in DFS
# 2 = completely processed

for start in range(n):

    if state[start] != 0:
        continue

    state[start] = 1

    # stack = (node, next adjacency index)
    stack = [(start, 0)]

    while stack:

        u, idx = stack[-1]

        if idx == len(g[u]):
            state[u] = 2
            stack.pop()
            continue

        v = g[u][idx]
        stack[-1] = (u, idx + 1)

        if state[v] == 0:

            state[v] = 1
            parent[v] = u
            stack.append((v, 0))

        elif state[v] == 1:

            # Found:
            #
            # v -> ... -> u -> v
            #
            # Reconstruct the cycle.

            cycle = []

            x = u

            while x != v:
                cycle.append((parent[x], x))
                x = parent[x]

            cycle.append((u, v))

            cycle.reverse()

            print(len(cycle))

            for a, b in cycle:
                print(a + 1, b + 1)

            sys.exit(0)


# ---------------------------------------------------------
# No cycle
# ---------------------------------------------------------

print(-1)
