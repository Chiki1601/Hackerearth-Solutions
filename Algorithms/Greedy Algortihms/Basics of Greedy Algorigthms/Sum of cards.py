# Write your code here
t = int(input())
for _ in range(t):
    n, x = map(int, input().strip().split())
    cards = list(map(int, input().strip().split()))
    total = abs(sum(cards))
    print(total // x + (total % x > 0))
