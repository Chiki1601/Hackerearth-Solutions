n = int(input())
counter = {'19': 0, '20': 0, 'other': 0}
for _ in range(n):
    s = input().strip()
    dates = filter(lambda x: x.isdigit(), s.split())
    weight = int(s[0] == 'G')
    for date in dates:
        if date in counter:
            counter[date] += 1 + weight
        else:
            counter['other'] += 1 + weight
if counter['19'] > counter['other'] or counter['20'] > counter['other']:
    print('Date')
else:
    print('No Date')
