def solution(record):
    answer = []
    uidDic = {}
    
    for i in range(len(record)-1, -1, -1):
        if record[i][0] == 'L':
            continue
        _, uid, name = record[i].split(" ")
        if not uid in uidDic:
            uidDic[uid] = name
    
    for i in range(len(record)):
        if record[i][0] == 'E':
            command, uid, _ = record[i].split(" ")
            answer.append("{}님이 들어왔습니다.".format(uidDic[uid]))
        elif record[i][0] == 'L':
            command, uid = record[i].split(" ")
            answer.append("{}님이 나갔습니다.".format(uidDic[uid]))
            
    
    return answer