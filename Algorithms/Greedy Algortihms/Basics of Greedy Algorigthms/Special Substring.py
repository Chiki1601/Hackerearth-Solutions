n, k = map(int, input().split())
s = input().strip()

# Create K consecutive non-empty substrings.
# First K-1 substrings have length 1.
# The last substring contains the remaining characters.

for i in range(1, k):
    print(i)

print(n)

# Identity permutation: 1 2 3 ... K
print(*range(1, k + 1))
