def solution(id_list, report, k):
    answer = dict.fromkeys(id_list, 0)
    count = dict.fromkeys(id_list, 0)
    compression_report = set(report)
    for user1, user2 in map(lambda x: x.split(), compression_report):
        count[user2] += 1
    for user1, user2 in map(lambda x: x.split(), compression_report):
        if (count[user2] >= k): 
            answer[user1] += 1
    return [answer[user] for user in answer]
