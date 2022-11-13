# Write your code here
t = int(input())
for _ in range(t):
    '''
    algorithm:
    The maximum number is 10**18, so we use 60 bits (2**59 < 10**18 < 2**60)
    for each bit 'b' between 0 and 59:
    a = number of 1s at 'b' position in the A[i]
    b = number of 0s at 'b' position in the A[i]
    we want to add the least possible of 1s on bit 'b', so
    if a > b, the 'b' bit of K is 1 otherwise 0
    Not too complicated to code, but there is simpler:
    We XOR the A[i] with all powers of 2 from 0 to 59
    For a power n, if the XORed value is less than the plain sum,
    then the (n-1)-th bit of K is 1, otherwise 0
    '''
    n = int(input())
    a = list(map(int, input().strip().split()))
    k = 0
    base = sum(a)
    for i in range(60):
        power = 2 ** i
        if sum(j ^ power for j in a) < base:
            k += power
    print(k)
