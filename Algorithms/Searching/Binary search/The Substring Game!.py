s = input().strip()

q = int(input())

numbers = list(map(int, input().split()))

n = len(s)

# counter[i] = number of substrings before index i
counter = [0] * (n + 1)

for i in range(n):
    counter[i + 1] = counter[i] + (n - i)

total = counter[n]

for k in numbers:

    if k > total:
        print(-1)
        continue

    # Find the largest index 'start' such that
    # counter[start] < k
    low = 0
    high = n - 1

    while low <= high:
        mid = (low + high) // 2

        if counter[mid] < k:
            low = mid + 1
        else:
            high = mid - 1

    start = high

    # Position inside the group starting at 'start'
    length = k - counter[start]

    print(s[start:start + length])
