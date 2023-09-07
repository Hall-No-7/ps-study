def solution(survey, choices):
    answer = ""

    table = {"R": 0, "T": 0, "C": 0, "F": 0, "J": 0, "M": 0, "A": 0, "N": 0}
    pair = ["RT", "CF", "JM", "AN"]

    for i in range(len(survey)):
        score = choices[i]
        if score == 4:
            continue

        table[survey[i][score // 4]] += abs(score - 4)

    for p in pair:
        if table[p[0]] >= table[p[1]]:
            answer += p[0]
        else:
            answer += p[1]

    return answer
