from queue import PriorityQueue
 
t = int(input())
for _ in range(t):
    n, x = map(int, input().strip().split())
    candies = list(map(int, input().strip().split()))
    total = sum(candies)
    if total <= x:
        print('YES')
    else:
        queue = PriorityQueue()
        for candy in candies:
            queue.put(-candy)
        queue.put(0)
        amount_time = 0
        while True:
            a = queue.get()
            if not a:
                break
            b = queue.get()
            if not b:
                amount_time -= a
                break
            amount_time -= b
            a -= b
            queue.put(a)
        if amount_time <= x:
            print('YES')
        else:
            print('NO')
