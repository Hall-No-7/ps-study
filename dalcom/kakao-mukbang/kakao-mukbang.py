def solution(food_times, k):
    answer = 0

    tmp = [(val, i) for i, val in enumerate(food_times)]
    total_time = sum(food_times)
    check = [False for i in range(len(food_times))]

    cycle_time = len(food_times)  # 음식 한 사이클 도는데 걸리는 시간 (남은 음식 개수)
    cycle_cnt = 0  # 사이클을 돈 횟수

    sort_times = sorted(tmp, key=lambda x: (x[0], -x[1]))

    if total_time <= k:
        return -1

    p = 0

    while cycle_time != 0 and k >= cycle_time:
        cnt = min(sort_times[p][0] - cycle_cnt, k // cycle_time)

        k -= cycle_time * cnt

        if cnt == sort_times[p][0] - cycle_cnt:
            check[sort_times[p][1]] = True
            cycle_time -= 1

            np = p + 1
            while np < len(sort_times) and sort_times[p][0] == sort_times[np][0]:
                cycle_time -= 1
                check[sort_times[np][1]] = True
                np += 1

            p = np

        cycle_cnt += cnt
    for idx, val in enumerate(check):
        if val:
            continue

        if k == 0:
            answer = idx + 1
            break
        k -= 1

    return answer
