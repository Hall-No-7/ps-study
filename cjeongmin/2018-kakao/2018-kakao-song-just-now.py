def parsing(music):
    token = []
    for i, c in enumerate(music):
        if c == '#':
            token[-1] = token[-1] + c
        else:
            token.append(c)
    return token

def find(m, music):
    i = 0
    while i + len(m) < len(music):
        if m == music[i:i+len(m)]:
            return True
        i += 1
    return False

def solution(m, musicinfos):
    answer = (-1, "(None)")
    m = parsing(m)
    for start, end, title, music in [info.split(",") for info in musicinfos]:
        music = parsing(music)
        start = start.split(":")
        end = end.split(":")
        start = int(start[0]) * 60 + int(start[1])
        end = int(end[0]) * 60 + int(end[1])
        
        duration = end - start + 1
        music = music * (duration // len(music)) + music[:duration % len(music)]
        if find(m, music) and answer[0] < duration:
            answer = (duration, title)
    return answer[1]
