# Write your code here
t = int(input())
for _ in range(t):
    flag = 0
    m, n = map(int, input().strip().split())
    boys = sorted(map(int, input().strip().split()))
    girls = sorted(map(int, input().strip().split()))
    if len(boys) > len(girls):
        print('NO')
    else:
        for i in range(len(boys)):
            if boys[i] <= girls[i]:
                print('NO')
                break
        else:
            print('YES')
