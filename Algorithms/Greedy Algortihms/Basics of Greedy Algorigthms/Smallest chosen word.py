# Write your code here
n1, n2, n3 = map(int, input().strip().split())
s1, s2, s3 = input().strip().split()
current_pos = 0
sorted_set = sorted(set(s2))
hash_array = [[] for _ in range(26)]
for i in range(n2):
    hash_array[ord(s2[i]) - 97].append(i)
x = ''
for c in sorted_set:
    if c < s3[0]:
        temp = [i for i in hash_array[ord(c) - 97] if i >= current_pos]
        lt = len(temp)
        if lt != 0:
            current_pos = temp[-1]
        x += c * lt
    elif c == s3[0]:
        temp = ''
        for i in range(n3 - 1):
            if c == s3[i]:
                temp += c
                if s3[i + 1] != s3[i]:
                    if s3[i + 1] < s3[i]:
                        temp = ''
                    break
        if temp and n3 != s3.count(c):
            x += c * len([i for i in hash_array[ord(c) - 97] if i >= current_pos])
print(s1 + x + s3)
