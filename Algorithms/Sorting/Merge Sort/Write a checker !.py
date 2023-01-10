n = int(input())
users = []
count = 0
ans = []
for k in range(n):
    users.append(input().strip().split())
for i in range(n):
    for j in range(i):
        if users[j][0] == users[i][0] or users[j][1] == users[i][1] or \
                users[j][2] == users[i][2] or users[j][3] == users[i][3]:
            count += 1
            ans.append(f'{str(j + 1)} {str(i + 1)}')
print(count)
print(*ans, sep='\n')
