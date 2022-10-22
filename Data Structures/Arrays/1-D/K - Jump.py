from bisect import bisect_right
 
k = int(input())
n = int(input())
a = list(map(int, input().strip().split()))
lengths = [float('-inf')]
for i in a:
    j = bisect_right(lengths, i - k)
    if j == len(lengths):
        lengths.append(i)
    else:
        lengths[j] = min(i, lengths[j])
print(len(lengths) - 1)
