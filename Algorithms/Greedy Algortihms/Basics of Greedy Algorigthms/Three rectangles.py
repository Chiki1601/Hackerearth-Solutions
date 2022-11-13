# Write your code here
t = int(input())
for _ in range(t):
    h, w = map(int, input().strip().split())
    if h % 3 == 0 or w % 3 == 0:
        print(0)
    else:
        size = (h, w)
        mx = max(size)
        mn = min(size)
        h1 = round(mx / 3)
        h2 = mx - h1
        a1 = h1 * mn
        w1 = mn // 2
        w2 = mn - w1
        a2 = w1 * h2
        a3 = w2 * h2
        res1 = (max(a1, a2, a3) - min(a1, a2, a3))
        h1 = round(mn / 3)
        h2 = mn - h1
        a1 = h1 * mx
        w1 = mx // 2
        w2 = mx - w1
        a2 = w1 * h2
        a3 = w2 * h2
        res2 = (max(a1, a2, a3) - min(a1, a2, a3))
        print(min(res1, res2, mn))
