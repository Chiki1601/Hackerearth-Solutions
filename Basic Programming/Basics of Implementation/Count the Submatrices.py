def Solve(M, N, P, Matrix):
    # write your code here
    # return your answer
    res = 0
    for i in range(M):
        sums = [0] * N
        for j in range(i, M):
            counts = [0] * 200
            counts[0] = 1
            for k in range(N):
                sums[k] += Matrix[j][k]
            x = 0
            for k in range(N):
                x = (x + sums[k]) % P
                res += counts[x]
                counts[x] += 1
    return res


M, N, P = map(int, input().split())

Matrix = []

for _ in range(M):
    Matrix.append(list(map(int, input().split())))

out_ = Solve(M, N, P, Matrix)

print(out_)
