percents = [10, 20, 30, 40]

g_users = []
g_emoticons = []
g_answer = [0, 0]


def recur(depth, user):
    global g_answer

    if depth == len(g_emoticons):
        cnt = 0
        total_price = 0
        for i, data in enumerate(user):
            if data == 0:
                continue
            _, price = g_users[i]
            if data >= price:
                cnt += 1
            else:
                total_price += data

        if g_answer[0] < cnt:
            g_answer = [cnt, total_price]
        elif g_answer[0] == cnt and g_answer[1] < total_price:
            g_answer = [cnt, total_price]

        return

    tmp_user = [x for x in user]
    for percent in percents:
        for i, user_info in enumerate(g_users):
            per, _ = user_info
            if percent >= per:
                user[i] += g_emoticons[depth] * (100 - percent) / 100
        recur(depth + 1, user)
        user = [x for x in tmp_user]


def solution(users, emoticons):
    global g_users, g_emoticons
    answer = []

    g_users = users
    g_emoticons = emoticons

    recur(0, [0 for _ in range(len(users))])
    answer = g_answer
    return answer


print(solution([[40, 10000], [25, 10000]], [7000, 9000]))
