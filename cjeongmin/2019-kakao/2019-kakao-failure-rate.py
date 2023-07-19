def upperBound(arr, x, lo, hi):
    while lo < hi:
        mid = (lo + hi) // 2
        if x < arr[mid]:
            hi = mid
        else:
            lo = mid + 1
    return lo

def solution(N, stages):
    answer = []
    
    stages.sort()
    prev = 0
    for level in range(1, N+1):
        curr = upperBound(stages, level, 0, len(stages))
        answer.append(
            (level, 0
            if len(stages) <= prev
            else (curr - prev) / (len(stages) - prev))
        )
        prev = curr
    
    return list(map(lambda x: x[0], sorted(answer, key=lambda x: -x[1])))
