from collections import Counter
 
s = input()
counter = Counter(s)
max_count = max(counter.values())
substrings = []
for i in counter:
    if counter[i] == max_count:
        substrings.append(i)
res = ''.join(substrings)
print(res[0:max_count + 1])
