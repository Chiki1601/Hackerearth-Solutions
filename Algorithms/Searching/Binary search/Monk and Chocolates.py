# Write your code here
t = int(input())
for _ in range(t):
    n, m = map(int, input().strip().split())
    s = input()
    if m >= n:
        print(n)
    else:
        freq = [0] * 58  # ord('z') - ord('A') + 1
        top_freq = 0
        ans = 0
        left = 0
        right = 1
        top_ele = s[0]
        freq[ord(top_ele) - 65] += 1  # ord('A') = 65
        while right < n:
            c = s[right]
            c_idx = ord(c) - 65
            freq[c_idx] += 1
            if c == top_ele:
                top_freq += 1
            else:
                if freq[c_idx] > top_freq:
                    top_freq = freq[c_idx]
                    top_ele = c
                while right - left + 1 - top_freq > m:
                    left += 1
                    freq[ord(s[left - 1]) - 65] -= 1
                    if s[left - 1] == top_ele:
                        top_freq = 0
                        for i in range(58):
                            if freq[i] > top_freq:
                                top_ele = chr(i + 65)
                                top_freq = freq[i]
            ans = max(ans, right - left + 1)
            right += 1
        print(ans)
