t = int(input())
for _ in range(t):
    n = int(input())
    a = input().strip().split()
    ones = [i for i in range(n) if a[i] == '1']
    ln_ones = len(ones)
    if not ln_ones:
        print(0)
    elif ln_ones % 3 != 0:
        print(-1)
    else:
        end_zeros = n - ones[-1] - 1
        first = ones[ln_ones // 3 - 1] + end_zeros + 1
        second = ones[2 * ln_ones // 3 - 1] + end_zeros + 1
        part_1 = int(''.join((a[:first])), 2)
        part_2 = int(''.join((a[first:second])), 2)
        part_3 = int(''.join((a[second:])), 2)
        print(part_1 % 1000000007 if part_1 == part_2 == part_3 else -1)
