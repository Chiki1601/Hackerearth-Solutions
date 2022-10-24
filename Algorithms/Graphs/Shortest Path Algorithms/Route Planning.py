# Write your code here
from sys import stdin
 
 
def solve():
    n, m = map(int, stdin.readline().strip().split())
    itineraries = []
    longest_itinerary = 0
    for _ in range(m):
        line = list(map(int, stdin.readline().strip().split()))
        longest_itinerary = max(longest_itinerary, line[0])
        itineraries.append(line[1:])
    dist = [-1] * (n + 1)
    waiting = [False] * (n + 1)
    dist[1] = 0
    waiting[1] = True
    on_bus = [False] * len(itineraries)
    time = 0
    last_change = 0
    while True:
        if time - last_change > 2 * longest_itinerary:
            break
        # For any bus rider that arrives at this station, rider can wait at station
        for idx, itinerary in enumerate(itineraries):
            station = itinerary[time % len(itinerary)]
            if on_bus[idx]:
                waiting[station] = True
        # If rider can be waiting at this station, rider can get on bus
        for idx, itinerary in enumerate(itineraries):
            station = itinerary[time % len(itinerary)]
            if waiting[station]:
                on_bus[idx] = True
        # If rider can be on the bus, station is reached at this time
        for idx, itinerary in enumerate(itineraries):
            station = itinerary[time % len(itinerary)]
            if on_bus[idx] and dist[station] == -1:
                dist[station] = time
                last_change = time
        time += 1
    print(' '.join(str(i) for i in dist[2:]))
 
 
solve()
