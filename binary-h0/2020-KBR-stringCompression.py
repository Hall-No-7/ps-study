def solution(s):
    answer = len(s)
    for i in range(len(s) // 2,  0, -1):
        count = 0
        tmpAnswer = len(s)
        for j in range(0, len(s)-i, i):
            msg = s[j:j+i]
            nextMsg = s[j+i:j+2*i]
            if msg == nextMsg:
                count += 1
            else:
                if not count == 0:
                    tmpAnswer -= i * count
                    if 9 > count:
                        tmpAnswer += 1
                    elif 99 > count:
                        tmpAnswer += 2
                    elif 999 > count:
                        tmpAnswer += 3
                    else:
                        tmpAnswer += 4
                    count = 0
        if not count == 0:
            tmpAnswer -= i * count
            if 9 > count:
                tmpAnswer += 1
            elif 99 > count:
                tmpAnswer += 2
            elif 999 > count:
                tmpAnswer += 3
            else:
                tmpAnswer += 4
        
        if tmpAnswer < answer:
            answer = tmpAnswer
        
    return answer