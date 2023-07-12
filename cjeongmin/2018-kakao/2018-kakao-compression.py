def solution(msg):
    answer = []
    
    i = 0
    last = i
    table = {chr(ord('A') + i): i + 1 for i in range(26)}
    while i < len(msg):
        for j in range(i + 1, len(msg) + 1):
            word = msg[i:j]
            if word not in table:
                table[word] = len(table) + 1
                answer.append(table[msg[i:j-1]])
                i = j - 1
                last = i
                break
        else:
            i += 1
    answer.append(table[msg[last:i]])

    return answer
