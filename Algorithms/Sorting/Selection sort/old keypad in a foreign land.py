# Write your code here
n = int(input())
frequencies = list(map(int, input().strip().split()))
k = int(input())
key_sizes = list(map(int, input().strip().split()))
if n > sum(key_sizes):
    print('-1')
else:
    frequencies.sort(reverse=True)
    key_sizes.sort()
    ans = 0
    keystroke = 1
    x = 0
    for i in range(n):
        for j in range(k):
            if x < n:
                if key_sizes[j] > 0:
                    key_sizes[j] -= 1
                    ans += keystroke * frequencies[x]
                    x += 1
        keystroke = keystroke + 1
    print(ans)
