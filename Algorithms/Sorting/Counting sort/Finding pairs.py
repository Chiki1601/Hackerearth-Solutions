def modifiedCountingSort(arr):
    maxElement = max(arr)
    countArr = {}
 
    for element in arr:
        if element in countArr:
            countArr[element]+=1
        else:
            countArr[element]=1
 
    ans = 0
    for index in countArr:
        count=countArr[index]
        ans+= ((count)*(count+1))//2
    return ans
 
n = int(input())
for _ in range(n):
    size = int(input())
    print(modifiedCountingSort(list(map(int,input().split()))))
