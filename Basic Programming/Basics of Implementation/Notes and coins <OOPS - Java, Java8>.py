n = int(input())
notes = []
coins = []
for _ in range(n):
    s, val = input().strip().split()
    val = int(val)
    if 'Coin' == s:
        coins.append(val)
    elif 'Note' == s:
        notes.append(val)
print('Coins :')
print(*coins, sep='\n')
print('Notes :')
print(*notes, sep='\n')
