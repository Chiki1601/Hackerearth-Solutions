t=int(input())
for i in range(t):
    m,p=map(int,input().split())
    print(str(bin(m^p)).count("1"))
