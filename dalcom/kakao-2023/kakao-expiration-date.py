def calc_time(time, month):
    y, m, d = map(int, time.split("."))

    t = y * 12 * 28 + m * 28 + d
    return t + month * 28


def solution(today, terms, privacies):
    answer = []

    dic = dict()

    y, m, d = map(int, today.split("."))
    tt = y * 12 * 28 + m * 28 + d

    for term in terms:
        type, month = term.split()
        dic[type] = int(month)

    for i, privacy in enumerate(privacies, 1):
        time, type = privacy.split()
        if calc_time(time, dic[type]) <= tt:
            answer.append(i)

    return answer
