def solution(N, stages):
    answer = []
    stages.sort()
    # print(stages)
    stage_len = len(stages)
    fail_ratios = []
    faile_ratio = 0.0
    i = 0
    for stage in range(1, N + 1, 1):
        not_success = 0
        success = stage_len
        while i < stage_len:
            s = stages[i]
            # print(s, stage)
            i += 1
            if stage == s:
                not_success += 1
            elif stage < s:
                i -= 1
                success = stage_len - (i)
                break
                
        if (i == stage_len) and (stage < N + 1):
            i -= 1
            success = stage_len - (i)
            
        faile_ratio = not_success / (not_success + success)
        fail_ratios.append((stage, faile_ratio))
    fail_ratios.sort(key=lambda x: x[1], reverse=True)
    answer = [s for s, _ in fail_ratios]

    return answer