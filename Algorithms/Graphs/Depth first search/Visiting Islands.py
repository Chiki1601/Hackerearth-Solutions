from collections import deque
 
t = int(input())
for _ in range(t):
    n = int(input())
    islands = list(map(int, input().strip().split()))
    counts = [0] * n
    max_visit = -1
    ans = -1
    for i in range(n):
        if counts[i]:
            if max_visit < counts[i]:
                max_visit = counts[i]
                ans = i
        else:
            stack = deque([i])
            counts[i] = -1
            count = -1
            j = islands[i]
            while not counts[j]:
                stack.append(j)
                count -= 1
                counts[j] = count
                j = islands[j]
            if counts[j] < 0:
                while j != stack[-1]:
                    counts[stack.pop()] = counts[j] - count + 1
                counts[stack.pop()] = counts[j] - count + 1
            count = 1 + counts[j]
            while stack:
                counts[stack.pop()] = count
                count += 1
            if max_visit < counts[i]:
                max_visit = counts[i]
                ans = i
    print(ans)
