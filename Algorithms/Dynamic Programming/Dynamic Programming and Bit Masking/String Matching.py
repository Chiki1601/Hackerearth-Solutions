from collections import defaultdict
 
string = input().strip()
n = int(input())
s = input().strip().split()
freq = defaultdict(int)
size = len(string)
for i in s:
    freq[i] += 1
ans = left = right = 0
count = n
while left < size and right < size:
    if string[right] in freq:
        freq[string[right]] -= 1
        if 0 == freq[string[right]]:
            count -= 1
    if 0 == count:
        while 0 == count and left <= right:
            ans += size - right
            if string[left] in freq:
                freq[string[left]] += 1
                if 1 == freq[string[left]]:
                    count += 1
            left += 1
    right += 1
print(ans)
