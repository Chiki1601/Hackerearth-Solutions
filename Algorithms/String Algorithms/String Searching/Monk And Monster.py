# Write your code here
t = int(input())
for _ in range(t):
    p = input().strip()
    q = input().strip()
    n = int(input())
    costs = list(map(int, input().strip().split()))
    pq = q + "#" + p
    lp = len(p)
    lq = len(q)
    ln = len(pq)
    lps = [0] * ln
    for x in range(1, ln):
        y = lps[x - 1]
        while y > 0 and pq[y] != pq[x]:
            y = lps[y - 1]
        if pq[y] == pq[x]:
            y += 1
        lps[x] = y
    dp = [0] * (lp + 1)
    for i in range(1, lp + 1):
        if lps[i + lq] == lq:
            dp[i] = max(dp[i - 1], dp[i - lq] + costs[i - lq])
        else:
            dp[i] = dp[i - 1]
    print(dp[lp])
