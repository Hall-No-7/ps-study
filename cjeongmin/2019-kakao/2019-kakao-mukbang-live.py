import heapq


def solution(food_times, k):
    if sum(food_times) <= k:
        return -1
    
    answer = 0
    food_times = [[food_times[i], i + 1] for i in range(len(food_times))]
    heapq.heapify(food_times)
    
    cycle = 0
    time = 0
    while time + (food_times[0][0] - cycle) * len(food_times) < k:
        food_time, _ = heapq.heappop(food_times)
        t = food_time - cycle
        cycle += t
        time += t * (len(food_times) + 1)
        
    food_times.sort(key=lambda x: x[1])
    return food_times[(k - time) % len(food_times)][1]
