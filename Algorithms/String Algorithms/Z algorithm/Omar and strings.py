s = input().strip()
 
 
def is_palindrome(x, start, length):
    offset = start
    end_offset = start + length - 1
    for i in range(length // 2):
        if x[offset] != x[end_offset]:
            return False
        offset += 1
        end_offset -= 1
    return True
 
 
def get_palindromic_suffix(x):
    for i in range(len(x)):
        if is_palindrome(x, i, len(x) - i):
            return x[i:]
 
 
def get_palindromic_prefix(x):
    for i in reversed(range(len(x))):
        if is_palindrome(x, 0, i + 1):
            return x[:i + 1]
 
 
def z_function(str1, str2):
    z_text = str1 + '$' + str2
    z_array = [0] * len(z_text)
    left = -1
    right = -1
    for i in range(1, len(z_text)):
        if i > right:
            count = 0
            while i + count < len(z_text) and z_text[i + count] == z_text[count]:
                count += 1
            z_array[i] = count
            if count > 1:
                left = i
                right = left + count - 1
        elif left < i <= right:
            j = i - left
            if z_array[j] < right - i + 1:
                z_array[i] = z_array[j]
            else:
                left = i
                count = right - left + 1
                while i + count < len(z_text) and z_text[i + count] == z_text[count]:
                    count += 1
                z_array[i] = count
                right = left + count - 1
    return z_array[len(str1) + 1:]
 
 
omeric = get_palindromic_suffix(s) + get_palindromic_prefix(s)
z = z_function(omeric, omeric)
counts = [0] * (len(omeric) + 1)
for i in z:
    counts[i] += 1
for i in reversed(range(len(counts) - 1)):
    counts[i] += counts[i + 1]
print(omeric)
print(' '.join(str(x) for x in counts[1:]))
