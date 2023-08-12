from itertools import combinations
from collections import defaultdict


def solution(orders, course):
    answer = []
    
    cnt = {}
    for size in course:
        cnt[size] = defaultdict(int)
        for order in orders:
            for combination in combinations(order, size):
                cnt[size][tuple(sorted(combination))] += 1
                
    for size in cnt:
        arr = sorted(cnt[size].items(), key=lambda x: -x[1])
        if len(arr) == 0:
            continue
        m = arr[0][1]
        if m < 2:
            continue
        for v in arr:
            if v[1] != m:
                break
            answer.append("".join(v[0]))
    
    return sorted(answer)
