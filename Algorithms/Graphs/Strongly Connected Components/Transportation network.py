#Write your code here
n, q = map(int, input().strip().split())
railway = 0
road = 0
for _ in range(q):
    b, u, v = map(int, input().strip().split())
    if b == 1:
        railway += 1
    else:
        road += 1
    print('YES' if railway == road else 'NO')
