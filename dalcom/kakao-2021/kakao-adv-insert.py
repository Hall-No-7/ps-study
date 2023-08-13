"""
처음 효율성 틀린 풀이
"""


def add_time(time_a, time_b):
    hour_a, minute_a, sec_a = map(int, time_a.split(":"))
    hour_b, minute_b, sec_b = map(int, time_b.split(":"))

    result_h, result_m, result_s = 0, 0, 0
    if sec_a + sec_b >= 60:
        minute_b += 1
        result_s -= 60
    result_s += sec_a + sec_b

    if minute_a + minute_b >= 60:
        hour_b += 1
        result_m -= 60
    result_m += minute_a + minute_b

    result_h += hour_b + hour_a

    return "%02d:%02d:%02d" % (result_h, result_m, result_s)


def calc_time(time_a, time_b):
    hour_a, minute_a, sec_a = map(int, time_a.split(":"))
    hour_b, minute_b, sec_b = map(int, time_b.split(":"))

    if time_a > time_b:
        hour_a, minute_a, sec_a, hour_b, minute_b, sec_b = (
            hour_b,
            minute_b,
            sec_b,
            hour_a,
            minute_a,
            sec_a,
        )

    result_h, result_m, result_s = 0, 0, 0

    if sec_b - sec_a < 0:
        minute_b -= 1
        result_s += 60
    result_s += sec_b - sec_a

    if minute_b - minute_a < 0:
        hour_b -= 1
        result_h += 60
    result_m += minute_b - minute_a

    result_h += hour_b - hour_a

    return "%02d:%02d:%02d" % (result_h, result_m, result_s)


def solution(play_time, adv_time, logs):
    answer = "99:59:59"
    max_time = "00:00:00"

    possible = ["00:00:00"]
    log_times = []

    for log in logs:
        time_a, time_b = log.split("-")
        possible.append(time_a)
        log_times.append((time_a, time_b))

    for adv_start_time in possible:
        adv_end_time = add_time(adv_start_time, adv_time)
        result = "00:00:00"
        for log_start_time, log_end_time in log_times:
            if log_start_time > adv_end_time or log_end_time < adv_start_time:
                continue

            time_a = (
                adv_start_time if adv_start_time >= log_start_time else log_start_time
            )
            time_b = adv_end_time if adv_end_time <= log_end_time else log_end_time

            result = add_time(result, calc_time(time_a, time_b))

        if max_time <= result:
            if max_time == result:
                answer = min(answer, adv_start_time)
            else:
                answer = adv_start_time
            max_time = result
            print(adv_start_time, adv_end_time, result)

    return answer


"""
답안 풀이
"""


def solution(play_time, adv_time, logs):
    play_time = str_to_int(play_time)
    adv_time = str_to_int(adv_time)
    all_time = [0 for i in range(play_time + 1)]

    for l in logs:
        start, end = l.split("-")
        start = str_to_int(start)
        end = str_to_int(end)
        all_time[start] += 1
        all_time[end] -= 1

    for i in range(1, len(all_time)):
        all_time[i] = all_time[i] + all_time[i - 1]

    for i in range(1, len(all_time)):
        all_time[i] = all_time[i] + all_time[i - 1]

    most_view = 0
    max_time = 0
    for i in range(adv_time - 1, play_time):
        if i >= adv_time:
            if most_view < all_time[i] - all_time[i - adv_time]:
                most_view = all_time[i] - all_time[i - adv_time]
                max_time = i - adv_time + 1
        else:
            if most_view < all_time[i]:
                most_view = all_time[i]
                max_time = i - adv_time + 1

    return int_to_str(max_time)


def str_to_int(time):
    h, m, s = time.split(":")
    return int(h) * 3600 + int(m) * 60 + int(s)


def int_to_str(time):
    h = time // 3600
    h = "0" + str(h) if h < 10 else str(h)
    time = time % 3600
    m = time // 60
    m = "0" + str(m) if m < 10 else str(m)
    time = time % 60
    s = "0" + str(time) if time < 10 else str(time)
    return h + ":" + m + ":" + s
