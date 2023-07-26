def compression(s, length):
    ret = ""
    cnt = 1
    pattern = s[:length]
    for i in range(length, len(s), length):
        if pattern == s[i:i+length]:
            cnt += 1
        else:
            ret += f"{cnt if cnt > 1 else ''}{pattern}"
            cnt = 1
            pattern = s[i:i+length]
    return ret + f"{cnt if cnt > 1 else ''}{pattern}"
    

def solution(s):
    return min(list(map(lambda x: len(compression(s, x)), range(1, len(s) // 2 + 1))) + [len(s)])
