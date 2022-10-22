N = int(input())
xs = input()
xs = [int(x) for x in xs.split()]
Q = int(input())
qs = []
for i in range(Q):
    q = input()
    [l, r] = q.split()
    qs.append((int(l), int(r)))
 
# number to frequency dictionary 
nf = {}
for x in xs:
    f = nf.get(x, 0)
    nf[x] = f + 1
 
# frequency to sum of numbers of the same frequency dictionary 
fn = {}
for k,v in nf.items():
    ns = fn.get(v, 0)
    fn[v] = ns + k*v
 
# list with its index as the frequency and the value as the sum of numbers of this frequency 
fs = []
for i in range(max(fn.keys()) + 1):
    fs.append(fn.get(i, 0))
 
# solution 
for (l, r) in qs:
    print(sum(fs[l:r+1]))
