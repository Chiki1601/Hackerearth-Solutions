import sys

input = sys.stdin.buffer.readline

# Read N
n = int(input())

# Read node values
a = list(map(int, input().split()))

# Find node having maximum value
center = max(range(n), key=lambda i: a[i]) + 1

# Construct a star:
# every other node is directly connected to center
out = []

for node in range(1, n + 1):
    if node != center:
        out.append(f"{center} {node}")

sys.stdout.write("\n".join(out))
