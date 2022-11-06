import math 
def countRectangle(n): 
    cnt = 0
    for l in range(1, int(math.sqrt(n)) + 1): 
        h = l 
        while(h * l <= n): 
            cnt += 1
            h += 1
    return cnt 
  
for _ in range(int(input())):
    print(countRectangle(int(input()))) 
