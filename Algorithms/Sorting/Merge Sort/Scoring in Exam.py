size, queries = map(int,input().split())
time = list(map(int,input().split()))
scores = list(map(int,input().split()))
 
finalArr = [ list(x) for x in zip(scores,time) ]
finalArr.sort(reverse=True)
 
for _ in range(queries):
    size = int(input())
    print(sum(y for x,y in finalArr[:size]))
