# Write your code here
n = int(input())
degrees = map(int, input().split())
print('Yes' if sum(degrees) == 2 * (n - 1) else 'No')
