mod = 1000000007
 
 
def solve(N):
    # Write your code here
    count = [0] * 10
    curr = [0] * 10
    res = 0
    for i in map(int, N):
        if i > 0:
            res += curr[i]
            res %= mod
            curr[i] += (count[i - 1] * (count[i - 1] - 1)) // 2
            curr[i] %= mod
        count[i] += 1
    return res
 
 
T = int(input())
for _ in range(T):
    N = input()
 
    out_ = solve(N)
    print(out_)
