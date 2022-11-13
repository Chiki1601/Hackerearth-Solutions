# Write your code here
t = int(input())
for _ in range(t):
    n = int(input())
    types = list(map(int, input().strip().split()))
    times = list(map(int, input().strip().split()))
    a = [list(map(int, input().strip().split())) for _ in range(3)]
    steps = ((0, 1, 2), (0, 2, 1), (1, 0, 2), (1, 2, 0), (2, 0, 1), (2, 1, 0))
    ans = 10 ** 18
    for x in steps:
        for y in steps:
            rep_types = types.copy()
            rep_times = times.copy()
            i = j = effort = total = 0
            while total != n:
                while not rep_types[x[i]]:
                    i += 1
                while not rep_times[y[j]]:
                    j += 1
                res = min(rep_types[x[i]], rep_times[y[j]])
                rep_types[x[i]] -= res
                rep_times[y[j]] -= res
                total += res
                effort += res * a[x[i]][y[j]]
            ans = min(ans, effort)
    print(ans)
