def minute_to_time(minute):
    hour = minute // 60
    minute = minute % 60
    return f"{hour:0>2}:{minute:0>2}"


def solution(n, t, m, timetable):
    timetable = sorted([
        int(hour) * 60 + int(minute) 
        for hour, minute 
        in [time.split(":") for time in timetable]
    ])
    
    i = 0
    cnt = 0
    curr_time = 540
    for _ in range(n):
        cnt = 0
        while (
            cnt < m 
            and i < len(timetable)
            and timetable[i] <= curr_time
        ):
            i += 1
            cnt += 1
        curr_time += t
    curr_time = curr_time - t if cnt < m else timetable[i-1] - 1
    return minute_to_time(curr_time)
