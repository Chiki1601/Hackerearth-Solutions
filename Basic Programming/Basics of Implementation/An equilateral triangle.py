n = int(input())
print(sum((i + 1) * i * ((n - i) // 2) // 2 for i in range(n)))
