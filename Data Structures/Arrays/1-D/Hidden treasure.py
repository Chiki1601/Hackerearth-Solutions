def solve(n, nums):
    freq = {}
    pairs = 0

    for num in nums:
        digit_sum = 0
        x = num

        while x > 0:
            digit_sum += x % 10
            x //= 10

        pairs += freq.get(digit_sum, 0)

        freq[digit_sum] = freq.get(digit_sum, 0) + 1

    return pairs
n = int(input())
nums = list(map(int, input().split()))

out_ = solve(n, nums)
print (out_)
