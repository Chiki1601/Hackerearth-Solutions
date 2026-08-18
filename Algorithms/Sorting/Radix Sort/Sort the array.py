n = int(input())
arr = list(map(int, input().split()))


def counting_sort(arr, place):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    # Count occurrences of the current digit
    for x in arr:
        digit = (x // place) % 10
        count[digit] += 1

    # Prefix sum
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Stable counting sort
    for i in range(n - 1, -1, -1):
        x = arr[i]
        digit = (x // place) % 10

        output[count[digit] - 1] = x
        count[digit] -= 1

    return output


# Find maximum value
maximum = max(arr)

place = 1

while maximum // place > 0:
    arr = counting_sort(arr, place)

    # Print array after this pass
    print(*arr)

    place *= 10

    
