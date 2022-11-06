t = int(input())
for i in range(t):
	n = int(input())
	a = input()
	a = list(map(int, a.split()))
	invList = [a.index(i) + 1 for i in range(1, len(a) + 1)]
	#print(invList)
	if a == invList:
	    print("inverse")
	else:
	    print("not inverse")
