def solution(record):
    answer = []
    users = {}
    for log in record:
        tokens = log.split()
        if tokens[0] == 'Enter':
            users[tokens[1]] = tokens[2]
            answer.append(f'#{tokens[1]}#님이 들어왔습니다.')
        elif tokens[0] == 'Leave':
            answer.append(f'#{tokens[1]}#님이 나갔습니다.')
        else:
            users[tokens[1]] = tokens[2]
    
    for i, log in enumerate(answer):
        a = 0
        b = log[1:].find('#')
        userId = log[1:b+1]
        answer[i] = log.replace(f'#{userId}#', users[userId])
    return answer
