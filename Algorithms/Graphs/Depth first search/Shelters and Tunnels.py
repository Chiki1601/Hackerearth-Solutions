n = int(input())
shelters = [0] * (n + 1)
for _ in range(n - 1):
    x, y = map(int, input().strip().split())
    shelters[x] += 1
    shelters[y] += 1
max_seen = max(shelters)
good_shelters = [i for i, v in enumerate(shelters) if i != 0 and v == max_seen]
print(len(good_shelters))
print(' '.join(map(str, good_shelters)))
