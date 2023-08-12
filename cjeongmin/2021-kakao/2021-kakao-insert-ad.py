def convert_time_to_seconds(time):
    hour = int(time[0:2]) * 60 * 60
    minute = int(time[3:5]) * 60
    second = int(time[6:8])
    return hour + minute + second


def convert_seconds_to_time(seconds):
    hour = seconds // (60 * 60)
    minute = seconds // 60 % 60
    second = seconds % 60
    return f"{hour:0>2}:{minute:0>2}:{second:0>2}"


def solution(play_time, adv_time, logs):
    answer = 0
    
    play_time = convert_time_to_seconds(play_time)
    adv_time = convert_time_to_seconds(adv_time)
    logs = list(map(lambda t: (convert_time_to_seconds(t.split("-")[0]), convert_time_to_seconds(t.split("-")[1])), logs))
    
    dp = [0] * (play_time + 1)
    
    # [0, 0, 1, 1, 0, -2] 시작과 끝
    for log in logs:
        dp[log[0]] += 1
        dp[log[1]] -= 1
        
    # [0, 0, 1, 2, 2, 0] 동시 시청자
    for t in range(1, play_time):
        dp[t] = dp[t] + dp[t - 1]
    
    # [0, 0, 1, 3, 5, 0] 누적 시청자
    for t in range(1, play_time):
        dp[t] = dp[t] + dp[t - 1]
    
    max_viewership = 0
    for t in range(1, play_time):
        if t >= adv_time:
            if max_viewership < dp[t] - dp[t - adv_time]:
                max_viewership = dp[t] - dp[t - adv_time]
                answer = t - adv_time + 1
        else:
            max_viewership = max(max_viewership, dp[t])
            if max_viewership < dp[t]:
                max_viewership = dp[t]
                answer = t - adv_time + 1
    
    return convert_seconds_to_time(answer)
