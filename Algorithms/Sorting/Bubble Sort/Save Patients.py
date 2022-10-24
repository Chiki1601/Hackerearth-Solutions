n = int(input())
vaccines = list(map(int, input().strip().split()))
midichlorians = list(map(int, input().strip().split()))
count = 0
ln = len(vaccines)
for i in range(ln):
    count += (vaccines[i] > midichlorians[i])
print('Yes' if count == ln else 'No')
