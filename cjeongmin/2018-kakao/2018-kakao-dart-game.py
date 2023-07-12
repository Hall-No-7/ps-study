def solution(dartResult):
    answer = []
    bonus = {
        "S": 1,
        "D": 2,
        "T": 3
    }
    
    n, flag = 0, False
    for c in dartResult:
        if '0' <= c <= '9':
            if flag:
                answer.append(n)
                n = 0
                flag = False
            n *= 10
            n += int(c)
        elif c in bonus:
            n = n ** bonus[c]
            flag = True
        else:
            answer.append(n)
            n = 0
            flag = False
            if c == '*':
                answer[-1] *= 2
                if len(answer) > 1:
                    answer[-2] *= 2
            else:
                answer[-1] *= -1
    if n:
        answer.append(n)
    return sum(answer)
