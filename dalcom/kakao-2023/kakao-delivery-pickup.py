def solution(cap, n, deliveries, pickups):
    answer = 0

    d_stack = []
    p_stack = []

    for i in range(n):
        if deliveries[i] != 0:
            d_stack.append([i, deliveries[i]])
        if pickups[i] != 0:
            p_stack.append([i, pickups[i]])

    if len(d_stack) + len(p_stack) == 0:
        return answer

    while len(d_stack) + len(p_stack) != 0:
        if len(d_stack) and len(p_stack):
            answer += (max(d_stack[-1][0], p_stack[-1][0]) + 1) * 2
        elif len(d_stack):
            answer += (d_stack[-1][0] + 1) * 2
        else:
            answer += (p_stack[-1][0] + 1) * 2
        d_cnt = cap
        p_cnt = 0

        for i in range(len(d_stack) - 1, -1, -1):
            if d_stack[i][1] > d_cnt:
                d_stack[i][1] -= d_cnt
                break
            else:
                d_cnt -= d_stack[i][1]
                d_stack.pop()

        for i in range(len(p_stack) - 1, -1, -1):
            if p_cnt + p_stack[i][1] > cap:
                p_stack[i][1] -= cap - p_cnt
                break
            else:
                p_cnt += p_stack[i][1]
                p_stack.pop()

    return answer
