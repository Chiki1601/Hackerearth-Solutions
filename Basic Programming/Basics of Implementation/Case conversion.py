def caseConversion(s):
    # Write your code here that converts the given camel case string s  and
    # returns a snake case version of that string
    res = ''
    for c in s:
        if c.isupper():
            res += '_' + c.lower()
        else:
            res += c
    if res[0] == '_':
        res = res[1:]
    return res


T = int(input())
for _ in range(T):
    s = input()

    out_ = caseConversion(s)
    print(out_)
