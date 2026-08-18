import random


n, k = map(int, input().split())
a = list(map(int, input().split()))


# ---------------------------------------------------------
# Calculate X for a given binary array
# ---------------------------------------------------------
def calculate_score(arr):
    # prefix sum:
    # 1 -> +1
    # 0 -> -1
    #
    # A subarray is good when:
    # prefix[j] > prefix[i]
    #
    # Since prefix values are between -N and N,
    # we can count previous smaller prefixes using
    # a Fenwick tree.

    size = 2 * n + 5
    offset = n + 2

    bit = [0] * size

    def add(index):
        while index < size:
            bit[index] += 1
            index += index & -index

    def query(index):
        result = 0

        while index > 0:
            result += bit[index]
            index -= index & -index

        return result

    prefix = 0
    score = 0

    # Prefix sum 0 exists before the array
    add(offset)

    for x in arr:
        if x == 1:
            prefix += 1
        else:
            prefix -= 1

        idx = prefix + offset

        # Number of previous prefix sums < current prefix
        score += query(idx - 1)

        add(idx)

    return score


# ---------------------------------------------------------
# Build blocks from end positions
# ---------------------------------------------------------
def make_blocks(ends):
    blocks = []

    start = 0

    for end in ends:
        blocks.append(a[start:end])
        start = end

    return blocks


# ---------------------------------------------------------
# Try a particular set of blocks
# ---------------------------------------------------------
def evaluate_blocks(blocks):
    # A block with more ones is generally better at the
    # beginning because it creates more positive subarrays.

    order = list(range(k))

    order.sort(
        key=lambda i: (
            -sum(blocks[i]),
            -len(blocks[i])
        )
    )

    candidate = []

    for i in order:
        candidate.extend(blocks[i])

    return calculate_score(candidate), order


# ---------------------------------------------------------
# Initial equal-sized partition
# ---------------------------------------------------------
def equal_partition():
    ends = []

    for i in range(1, k + 1):
        # Guaranteed to be increasing and non-empty
        end = (i * n) // k
        ends.append(end)

    return make_blocks(ends)


best_score = -1
best_blocks = None
best_order = None


# ---------------------------------------------------------
# Candidate 1:
# Equal-sized blocks
# ---------------------------------------------------------
blocks = equal_partition()

score, order = evaluate_blocks(blocks)

if score > best_score:
    best_score = score
    best_blocks = blocks
    best_order = order


# ---------------------------------------------------------
# Candidate 2:
# Try partitions with random cuts
# ---------------------------------------------------------
ITERATIONS = 120

for _ in range(ITERATIONS):

    # Pick K-1 distinct cut positions
    cuts = random.sample(range(1, n), k - 1)
    cuts.sort()
    cuts.append(n)

    blocks = make_blocks(cuts)

    score, order = evaluate_blocks(blocks)

    if score > best_score:
        best_score = score
        best_blocks = blocks
        best_order = order


# ---------------------------------------------------------
# Candidate 3:
# Random partitions + random block permutations
# ---------------------------------------------------------
for _ in range(60):

    cuts = random.sample(range(1, n), k - 1)
    cuts.sort()
    cuts.append(n)

    blocks = make_blocks(cuts)

    order = list(range(k))
    random.shuffle(order)

    candidate = []

    for i in order:
        candidate.extend(blocks[i])

    score = calculate_score(candidate)

    if score > best_score:
        best_score = score
        best_blocks = blocks
        best_order = order


# ---------------------------------------------------------
# Output
# ---------------------------------------------------------

# The end positions are based on the ORIGINAL order of blocks.
ends = []
pos = 0

for block in best_blocks:
    pos += len(block)
    ends.append(pos)

for x in ends:
    print(x)

# Convert 0-based block IDs to 1-based
print(*[x + 1 for x in best_order])
