t = int(input())
vowels = 'aeiouAEIOU'
for _ in range(t):
    s = input()
    n = len(s)
    ans = 0
    for i, c in enumerate(s):
        if c in vowels:
            ans += (i + 1) * (n - i)
    print(ans)
