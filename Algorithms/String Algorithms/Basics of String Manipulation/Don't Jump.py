# Write your code here
import sys
 
lines = [e.replace('\n', '') for e in sys.stdin.readlines()]
i = 0
while i < len(lines) - 1:
    n = int(lines[i])
    if len(lines[i + 1]) > 0:
        p = list(map(int, lines[i + 1].strip().split()))
        stack = [0]
        prev = last = 0
        pattern = ''
        for e in p:
            while stack[-1] < e:
                pattern += 'C'
                prev += 1
                stack.append(prev)
            while stack[-1] >= e:
                last = stack.pop()
                pattern += 'K'
            if last != e:
                print(-1)
                break
        else:
            print(pattern)
    else:
        print('')
    i += 2
