def solution(record):
    answer = []
    nickname = dict()
    tmp = []  # enter: 0, leave: 1, change: 2

    for rec in record:
        parse = rec.split()
        cmd = parse[0]
        uid = parse[1]
        if cmd == "Enter":
            tmp.append((0, uid))
        elif cmd == "Leave":
            tmp.append((1, uid))
            continue
        else:
            tmp.append((2, uid))

        nickname[uid] = parse[2]

    for cmd, uid in tmp:
        name = nickname[uid]
        if cmd == 0:
            answer.append(f"{name}님이 들어왔습니다.")
        elif cmd == 1:
            answer.append(f"{name}님이 나갔습니다.")

    return answer
