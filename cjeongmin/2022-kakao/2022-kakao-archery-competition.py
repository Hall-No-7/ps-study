from collections import deque

"""
가장 크게 이기는 것을 기준으로 해야하는데...
가장 큰 점수를 기준으로 잡아서 틀렸었다.
"""

def calc_score(ryan, apeach):
    ryan_score, apeach_score = 0, 0
    
    for i in range(11):
        if ryan[i] or apeach[i]:
            if ryan[i] <= apeach[i]:
                apeach_score += 10 - i
            else:
                ryan_score += 10 - i
    
    return ryan_score, apeach_score


def get_better(v1, v2):
    for i in range(10, -1, -1):
        if v1[i] > v2[i]:
            return v1
        elif v1[i] < v2[i]:
            return v2
    return v1


def solution(n, info):
    answer = [0] * 11
    max_diff = 0
    
    q = deque()
    q.append((0, []))
    while q:
        cnt, now = q.popleft()
        
        if len(now) == 11:
            now[10] = n - cnt
            cnt = n
        
        if cnt == n:
            if len(now) < 11:
                now += [0] * (11 - len(now))  
            
            ryan_score, apeach_score = calc_score(now, info)
            if ryan_score <= apeach_score or ryan_score - apeach_score < max_diff:
                continue
                
            if ryan_score == max_diff:
                answer = get_better(answer, now.copy())
            else:
                max_diff = ryan_score - apeach_score
                answer = now.copy()
        else:
            idx = len(now)
            if cnt + info[idx] + 1 <= n:
                q.append((cnt + info[idx] + 1, now + [info[idx] + 1]))
            q.append((cnt, now + [0]))
    
    return answer if max_diff > 0 else [-1]
