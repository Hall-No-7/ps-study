def parsing(lines):
    logs = []
    for line in lines:
        date, S, T = line.split()
        S = (float(S[0:2]) * 60 * 60 
            + float(S[3:5]) * 60
            + float(S[6:8])
            + float(S[9:12]) / 1000) * 1000
        T = float(T[0:-1]) * 1000
        logs.append([S - T + 1, S])
    return sorted(logs, key=lambda x: x[1])

def solution(lines):
    answer = 0
    logs = parsing(lines)
    for i, log1 in enumerate(logs):
        count = 1
        j = i + 1
        while j < len(logs):
            log2 = logs[j]
            if log2[0] - log1[1] < 1000:
                count += 1
            j += 1
        answer = max(answer, count)
    return answer
