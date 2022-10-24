import re
from sys import stdin
 
for line in stdin.readlines():
    if '//' in line:
        blocks = re.split('//', line)
        blocks[0] = re.sub('->', '.', blocks[0])
        print('//'.join(blocks))
    else:
        print(re.sub('->', '.', line))
