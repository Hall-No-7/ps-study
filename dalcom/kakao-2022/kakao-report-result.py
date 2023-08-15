from collections import defaultdict


def solution(id_list, report, k):
    answer = [0 for _ in range(len(id_list))]

    report_info = defaultdict(set)
    report_cnt = defaultdict(int)

    for info in report:
        user_id, reported_id = info.split()
        report_info[user_id].add(reported_id)

    for reported_lst in report_info.values():
        for name in reported_lst:
            report_cnt[name] += 1

    for idx, user_id in enumerate(id_list):
        report_data = report_info[user_id]
        cnt = 0
        for data in report_data:
            if report_cnt[data] >= k:
                cnt += 1
        answer[idx] = cnt

    return answer
