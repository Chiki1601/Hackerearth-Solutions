import sys
from array import array

input = sys.stdin.buffer.readline

INF = 10 ** 9
NEG = -10 ** 9

# ------------------------------------------------------------
# Input
# ------------------------------------------------------------

n, q = map(int, input().split())

g = [[] for _ in range(n)]

for _ in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

LOG = n.bit_length()


# ------------------------------------------------------------
# Root the tree
# ------------------------------------------------------------

parent = array('i', [-1]) * n
depth = array('i', [0]) * n
tin = array('i', [0]) * n
tout = array('i', [0]) * n

order = []

timer = 0

# Positive value  -> enter node
# Negative value  -> exit node (~v)
stack = [0]
parent[0] = -1

while stack:
    x = stack.pop()

    if x >= 0:
        v = x

        tin[v] = timer
        timer += 1
        order.append(v)

        stack.append(~v)

        # Reverse is not required for correctness.
        for to in g[v]:
            if to == parent[v]:
                continue

            parent[to] = v
            depth[to] = depth[v] + 1
            stack.append(to)

    else:
        v = ~x
        tout[v] = timer - 1


# ------------------------------------------------------------
# Binary lifting
# ------------------------------------------------------------

up = [None] * LOG

up[0] = array('i', parent)

for j in range(1, LOG):
    prev = up[j - 1]
    cur = array('i', [-1]) * n

    for v in range(n):
        p = prev[v]

        if p != -1:
            cur[v] = prev[p]

    up[j] = cur


# ------------------------------------------------------------
# Ancestor / LCA
# ------------------------------------------------------------

def is_ancestor(a, b):
    return tin[a] <= tin[b] <= tout[a]


def lca(a, b):
    if tin[a] <= tin[b] <= tout[a]:
        return a

    if tin[b] <= tin[a] <= tout[b]:
        return b

    x = a

    for j in range(LOG - 1, -1, -1):
        p = up[j][x]

        if p != -1 and not (tin[p] <= tin[b] <= tout[p]):
            x = p

    return parent[x]


def jump(v, dist):
    bit = 0

    while dist:
        if dist & 1:
            v = up[bit][v]

        dist >>= 1
        bit += 1

    return v


# ------------------------------------------------------------
# Downward height
#
# down[v] = maximum distance from v to a node in subtree(v)
# ------------------------------------------------------------

down = array('i', [0]) * n

# Keep top 6 children.
#
# A query has at most 5 selected vertices, therefore a virtual
# node can have at most 5 child directions that need to be
# excluded. Keeping 6 candidates guarantees that one remaining
# candidate can be found.
top_children = [
    array('i', [-1]) * n
    for _ in range(6)
]

for v in reversed(order):

    d = 0

    t0 = t1 = t2 = t3 = t4 = t5 = -1
    v0 = v1 = v2 = v3 = v4 = v5 = -1

    for to in g[v]:

        if parent[to] != v:
            continue

        value = down[to] + 1

        if value > d:
            d = value

        if value > t0:
            t5, v5 = t4, v4
            t4, v4 = t3, v3
            t3, v3 = t2, v2
            t2, v2 = t1, v1
            t1, v1 = t0, v0
            t0, v0 = value, to

        elif value > t1:
            t5, v5 = t4, v4
            t4, v4 = t3, v3
            t3, v3 = t2, v2
            t2, v2 = t1, v1
            t1, v1 = value, to

        elif value > t2:
            t5, v5 = t4, v4
            t4, v4 = t3, v3
            t3, v3 = t2, v2
            t2, v2 = value, to

        elif value > t3:
            t5, v5 = t4, v4
            t4, v4 = t3, v3
            t3, v3 = value, to

        elif value > t4:
            t5, v5 = t4, v4
            t4, v4 = value, to

        elif value > t5:
            t5, v5 = value, to

    down[v] = d

    top_children[0][v] = v0
    top_children[1][v] = v1
    top_children[2][v] = v2
    top_children[3][v] = v3
    top_children[4][v] = v4
    top_children[5][v] = v5


# ------------------------------------------------------------
# sibling[v]
#
# Maximum child-subtree height of parent[v], excluding v.
# ------------------------------------------------------------

sibling = array('i', [0]) * n

for v in range(1, n):

    p = parent[v]

    c = top_children[0][p]

    if c != v and c != -1:
        sibling[v] = down[c] + 1
    else:
        c = top_children[1][p]

        if c != -1:
            sibling[v] = down[c] + 1


# ------------------------------------------------------------
# outside[v]
#
# Maximum distance from v to a vertex outside subtree(v).
#
# Needed when v is the root of the virtual tree.
# ------------------------------------------------------------

outside = array('i', [0]) * n

for v in order:

    p = parent[v]

    if p == -1:
        outside[v] = 0
    else:
        outside[v] = max(
            1,
            outside[p] + 1,
            sibling[v] + 1
        )


# ------------------------------------------------------------
# Path DP
#
# Suppose we move upward from v.
#
# sibling[v] describes the side branches at parent[v].
#
# plus[v][j]:
#   max(side_height(x) + distance(v,x))
#   for the next 2^j ancestors.
#
# minus[v][j]:
#   max(side_height(x) - distance(v,x))
#
# These allow path queries in O(log n).
# ------------------------------------------------------------

plus = [None] * LOG
minus = [None] * LOG

p0 = array('i', [NEG]) * n
m0 = array('i', [NEG]) * n

for v in range(n):

    if parent[v] != -1:
        p0[v] = sibling[v] + 1
        m0[v] = sibling[v] - 1

plus[0] = p0
minus[0] = m0


for j in range(1, LOG):

    half = 1 << (j - 1)

    prev_p = plus[j - 1]
    prev_m = minus[j - 1]

    cur_p = array('i', [NEG]) * n
    cur_m = array('i', [NEG]) * n

    prev_up = up[j - 1]

    for v in range(n):

        mid = prev_up[v]

        if mid == -1:
            continue

        a = prev_p[v]
        b = prev_p[mid] + half

        cur_p[v] = a if a > b else b

        a = prev_m[v]
        b = prev_m[mid] - half

        cur_m[v] = a if a > b else b

    plus[j] = cur_p
    minus[j] = cur_m


# ------------------------------------------------------------
# Range aggregation
#
# Distances are measured upward from start.
#
# [L, R] means all ancestors at distance L..R.
# ------------------------------------------------------------

def range_plus(v, L, R):

    if L > R:
        return NEG

    # Move to distance L-1 first.
    cur = v
    base = 0
    d = L - 1
    bit = 0

    while d:

        if d & 1:
            cur = up[bit][cur]
            base += 1 << bit

        d >>= 1
        bit += 1

    length = R - L + 1

    ans = NEG

    for j in range(LOG - 1, -1, -1):

        step = 1 << j

        if length >= step:

            value = plus[j][cur] + base

            if value > ans:
                ans = value

            cur = up[j][cur]
            base += step
            length -= step

    return ans


def range_minus(v, L, R):

    if L > R:
        return NEG

    cur = v
    base = 0
    d = L - 1
    bit = 0

    while d:

        if d & 1:
            cur = up[bit][cur]
            base += 1 << bit

        d >>= 1
        bit += 1

    length = R - L + 1

    ans = NEG

    for j in range(LOG - 1, -1, -1):

        step = 1 << j

        if length >= step:

            value = minus[j][cur] - base

            if value > ans:
                ans = value

            cur = up[j][cur]
            base += step
            length -= step

    return ans


# ------------------------------------------------------------
# Solve query
# ------------------------------------------------------------

def solve_query(vertices):

    # Remove duplicate vertices.
    terminals = list(set(vertices))

    # --------------------------------------------------------
    # Build virtual tree.
    #
    # k <= 5, therefore virtual tree has <= 2k-1 <= 9 nodes.
    # --------------------------------------------------------

    terminals.sort(key=tin.__getitem__)

    candidates = terminals[:]

    for i in range(len(terminals) - 1):
        candidates.append(
            lca(terminals[i], terminals[i + 1])
        )

    candidates.sort(key=tin.__getitem__)

    virtual = []

    last = -1

    for v in candidates:

        if v != last:
            virtual.append(v)
            last = v

    m = len(virtual)

    # --------------------------------------------------------
    # Build virtual-tree parent.
    # --------------------------------------------------------

    vparent = [-1] * m
    edge_len = [0] * m

    stack_v = []

    for i in range(m):

        v = virtual[i]

        while stack_v:
            p = virtual[stack_v[-1]]

            if tin[p] <= tin[v] <= tout[p]:
                break

            stack_v.pop()

        if stack_v:

            pidx = stack_v[-1]

            vparent[i] = pidx
            edge_len[i] = depth[v] - depth[virtual[pidx]]

        stack_v.append(i)

    # --------------------------------------------------------
    # Distance from every virtual node to nearest query vertex.
    #
    # Multi-source DP on the virtual tree.
    # --------------------------------------------------------

    terminal_set = set(terminals)

    nearest = [INF] * m

    for i, v in enumerate(virtual):

        if v in terminal_set:
            nearest[i] = 0

    # Bottom-up
    for i in range(m - 1, -1, -1):

        p = vparent[i]

        if p != -1:

            value = nearest[i] + edge_len[i]

            if value < nearest[p]:
                nearest[p] = value

    # Top-down
    for i in range(m):

        p = vparent[i]

        if p != -1:

            value = nearest[p] + edge_len[i]

            if value < nearest[i]:
                nearest[i] = value

    # --------------------------------------------------------
    # For each virtual node determine which original-tree
    # children are occupied by virtual-tree edges.
    # --------------------------------------------------------

    excluded = [[] for _ in range(m)]

    for i in range(1, m):

        p = vparent[i]

        pv = virtual[p]
        cv = virtual[i]

        # First real child from pv towards cv.
        first_child = jump(
            cv,
            depth[cv] - depth[pv] - 1
        )

        excluded[p].append(first_child)

    # --------------------------------------------------------
    # Check branches attached directly to virtual nodes.
    # --------------------------------------------------------

    answer = 0

    for i, v in enumerate(virtual):

        ex = excluded[i]

        best_branch = 0

        # At most 5 virtual child directions can be excluded.
        for rank in range(6):

            child = top_children[rank][v]

            if child == -1:
                break

            if child not in ex:
                best_branch = down[child] + 1
                break

        # If v is root of virtual tree, everything outside
        # subtree(v) is also a branch.
        if vparent[i] == -1:

            if outside[v] > best_branch:
                best_branch = outside[v]

        value = nearest[i] + best_branch

        if value > answer:
            answer = value

    # --------------------------------------------------------
    # Process every virtual-tree edge.
    #
    # Let:
    #
    #   a = descendant
    #   b = ancestor
    #
    # On the path a -> b:
    #
    # distance to selected vertices is
    #
    # min(
    #   nearest[a] + dist(a,x),
    #   nearest[b] + dist(b,x)
    # )
    #
    # There is only one switching point.
    # --------------------------------------------------------

    for i in range(1, m):

        p = vparent[i]

        a = virtual[i]
        b = virtual[p]

        D = depth[a] - depth[b]

        # No internal vertex.
        if D <= 1:
            continue

        da = nearest[i]
        db = nearest[p]

        # For position t from a:
        #
        # da + t <= db + D - t
        #
        # 2t <= db + D - da
        #
        switch = (db + D - da) // 2

        if switch < 0:
            switch = 0
        elif switch > D:
            switch = D

        # ----------------------------------------------------
        # a-side
        #
        # t = 1 ... switch
        #
        # nearest source is a-side.
        # ----------------------------------------------------

        r = min(switch, D - 1)

        if r >= 1:

            best = range_plus(a, 1, r)

            if best > NEG // 2:

                value = da + best

                if value > answer:
                    answer = value

        # ----------------------------------------------------
        # b-side
        #
        # t = switch+1 ... D-1
        #
        # nearest source is b-side.
        # ----------------------------------------------------

        L = max(1, switch + 1)

        if L <= D - 1:

            best = range_minus(a, L, D - 1)

            if best > NEG // 2:

                value = db + D + best

                if value > answer:
                    answer = value

    return answer


# ------------------------------------------------------------
# Queries
# ------------------------------------------------------------

out = []

for _ in range(q):

    data = list(map(int, input().split()))

    k = data[0]

    vertices = [x - 1 for x in data[1:k + 1]]

    out.append(str(solve_query(vertices)))


sys.stdout.write("\n".join(out))
