def solution(dartResult):
    try_num = 3
    S, D, T = "S", "D", "T"
    minus, double = "#", "*"
    i = 0
    stack = ""
    tmp_score = [0, 0, 0]
    score_idx = 0
    while i < len(dartResult):
        s = dartResult[i]
        if 48 <= ord(s) <=57:
            stack+=s
        elif 65 <= ord(s) <= 90:
            tmp_score[score_idx] = int(stack)
            stack = ""
            if s == "D":
                tmp_score[score_idx] = tmp_score[score_idx] * tmp_score[score_idx]
            elif s == "T":
                tmp_score[score_idx] = tmp_score[score_idx] * tmp_score[score_idx] * tmp_score[score_idx]
            score_idx += 1
        else:
            if s == "*":
                for j in range(min(3, score_idx) - 1, max(score_idx - 3, -1), -1):
                    tmp_score[j] *= 2
            else:
                tmp_score[score_idx-1] = -tmp_score[score_idx-1]
        i += 1
        
    return sum(tmp_score)