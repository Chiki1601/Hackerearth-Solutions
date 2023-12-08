t = int(input())
for _ in range(t):
    n, x, y = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    largest = 0
    j = 0
    freq = {}
    for i in range(n):
        freq[a[i]] = freq.get(a[i], 0) + 1
        while len(freq) > x:
            freq[a[j]] -= 1
            if freq[a[j]] == 0:
                del freq[a[j]]
            j += 1
        if len(freq) == x and y in freq:
            largest = max(largest, i - j + 1)
    print(largest)
