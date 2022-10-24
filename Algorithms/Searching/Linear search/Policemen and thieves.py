#Compiles only on Python 2.7.6 environment
def solution (A, K):
    # Write your code here
    ans=0 #To save the result 
    if K > len(A):
        for row in A:
             ans+=(min(row.count("T"),row.count("P")))
        return ans
        
    for row in A:
        arr_len = len(row)
        for i in range(arr_len):
            if row[i] == 'P':
                thieve_found = False
                for thief in range(max(0,i-K),min(i+K+1,arr_len)):
                    if row[thief] == 'T':
                        row[thief] = 'X'
                        thieve_found = True
                        break
                
                if thieve_found:
                    ans += 1
    return ans               
 
        
 
T = input()
for _ in xrange(T):
    N, K = map(int, raw_input().split())
    A = []
    for _ in xrange(N):
        A.append(raw_input().split())
    out_ = solution(A, K)
    print out_
