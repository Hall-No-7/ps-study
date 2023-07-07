import heapq

def calc_time(time, duration):
    et, H, M, S = 0, 3600000, 60000, 1000
    h, m, s = time.split(":")
    et += int(h)*H + int(m)*M + int(float(s) * S)
    duration = int(float(duration[:len(duration) - 1]) * S)
    return (et - duration, et)

def solution(lines):
    answer = 0
    end_heap = []
    lis = []
    for line in lines:
        _, time, duration = line.split(" ")
        sT, eT = calc_time(time, duration)
        lis.append((sT,eT))
    lis.sort()
    
    for sT, eT in lis:
        heapq.heappush(end_heap, eT)
        
        while end_heap[0] <= (sT - 999):
            heapq.heappop(end_heap)
        answer = max(answer, len(end_heap))
        
    return answer