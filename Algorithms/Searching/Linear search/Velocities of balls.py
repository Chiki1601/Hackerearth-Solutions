# Write your code here
import numpy as np
 
t = int(input())
for _ in range(t):
    n = int(input())
    x = np.array(input().strip().split(), dtype='int')
    v = np.array(input().strip().split(), dtype='int')
    times = []
    collide = []
    collided = []
    for i, (vi, xi) in enumerate(zip(v, x)):
        for j, (vj, xj) in enumerate(zip(v, x)):
            if i != j and xi < xj and vi > 0 > vj:
                time = abs(xi - xj) / abs(vi - vj)
                times.append(time)
                collide.append(i)
                collided.append(j)
    time_idxes = np.argsort(times)
    times.sort()
    collide = np.array(collide)[time_idxes]
    collided = np.array(collided)[time_idxes]
    sums = [0] * n
    idxes = list(range(n))
    for i, time in enumerate(times):
        sums[idxes[collide[i]]] += int(time)
        sums[idxes[collided[i]]] += int(time)
        idxes[collide[i]], idxes[collided[i]] = idxes[collided[i]], idxes[collide[i]]
    print(*sums, sep='\n')
