def solution(N, stages):
    answer = dict()

    sz = len(stages)
    cur = 1
    cnt = 0
    prev_cnt = 0

    for stage in sorted(stages):
        if cur != stage:
            while cur != stage and cur <= N:
                if len(stages) == prev_cnt:
                    answer[cur] = 0
                else:
                    answer[cur] = cnt / (len(stages) - prev_cnt)
                cur += 1
                prev_cnt += cnt
                cnt = 0
        cnt += 1

    while cur <= N:
        if len(stages) == prev_cnt:
            answer[cur] = 0
        else:
            answer[cur] = cnt / (len(stages) - prev_cnt)
        cur += 1
        prev_cnt += cnt
        cnt = 0

    result = []
    for stage in sorted(answer.items(), key=lambda x: (-x[1], x[0])):
        result.append(stage[0])

    return result
