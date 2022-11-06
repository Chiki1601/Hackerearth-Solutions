import math
for i in range(int(input())):
    n=int(input())
    a = [[j for j in input().strip()] for i in range(n)] 
    #print(a)
    for j in range(len(a)):
        for k in range(len(a[j])):
            if a[j][k]=="*":
                sr=j+1
                sc=k+1
                break
    moves = abs(math.ceil(n/2)-sr) + abs(math.ceil(n/2)-sc);
    print(moves)
