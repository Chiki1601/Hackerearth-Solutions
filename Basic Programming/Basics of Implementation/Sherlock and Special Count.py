for i in range(int(input())):
    n,k=map(int,input().split())
    if (k%2 or k>(n*n/2)):
        print("NO")
    else:
        print("YES")
