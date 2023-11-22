def solution(N, S):
    # Write your code here
    signals = S.split("0")
    return len(max(signals, key=len))


T = int(input())
for _ in range(T):
    N = int(input())
    S = input()

    out_ = solution(N, S)
    print(out_)
