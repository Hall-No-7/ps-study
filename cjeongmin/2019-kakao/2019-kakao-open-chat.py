def solution(record):
    answer = []
    users = {}
    for log in record:
        tokens = log.split()
        if tokens[0] == "Enter":
            users[tokens[1]] = tokens[2]
            answer.append((tokens[1], "님이 들어왔습니다."))
        elif tokens[0] == "Leave":
            answer.append((tokens[1], "님이 나갔습니다."))
        else:
            users[tokens[1]] = tokens[2]
    return list(map(lambda x: "".join([users[x[0]], x[1]]), answer))
