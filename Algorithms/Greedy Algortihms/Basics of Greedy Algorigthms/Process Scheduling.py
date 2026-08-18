import heapq

W = int(input())
N = int(input())

processes = []

for i in range(1, N + 1):
    B, R, D = map(int, input().split())

    # A process can never finish if its runtime is greater
    # than its own deadline or W.
    if R <= W and R <= D:
        processes.append((D, B, R, i))

# Process jobs in increasing deadline order
processes.sort()

# Min-heap:
# (benefit, runtime, process_id, deadline)
selected = []

total_time = 0

for D, B, R, idx in processes:
    total_time += R
    heapq.heappush(selected, (B, R, idx, D))

    # Effective deadline cannot exceed W
    limit = min(D, W)

    # Remove lowest-benefit jobs until the schedule is feasible
    while total_time > limit and selected:
        b, r, old_idx, old_d = heapq.heappop(selected)
        total_time -= r

# The selected jobs must be executed by deadline
answer = sorted(selected, key=lambda x: (x[3], x[2]))

print(len(answer))

if answer:
    print(*[job[2] for job in answer])
