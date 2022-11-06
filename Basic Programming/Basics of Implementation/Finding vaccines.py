# Write your code here
noOfVaccine = int(input())
lenOfVirus = int(input())
virus = input()
v = [0]*2
for i in virus:
    if i == 'C':
        v[0] += 1
    elif i == 'G':
        v[1] += 1
 
ans = 0
number = 0
for j in range(noOfVaccine):
    le = int(input())
    vacc = input()
    temp = [0]*2        #A temp array used to keep the count of "C" and "G" molecule 
    for i in vacc:
        if i == 'C':
            temp[0]+=1
        elif i =='G':
            temp[1]+=1
    score = v[0]*temp[1] + v[1]*temp[0]
    if score > ans:
        ans = score
        number = j+1
 
print(number)
