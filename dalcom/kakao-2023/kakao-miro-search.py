def solution(n, m, x, y, r, c, k):
    x, y = y, x

    row = r - y
    col = c - x

    rcnt = abs(row)
    ccnt = abs(col)

    answer = ""
    rest_cnt = k - rcnt - ccnt
    if rest_cnt < 0 or rest_cnt % 2 != 0:
        answer = "impossible"
        return answer

    down_cnt = n - r if row > 0 else n - y
    left_cnt = c - 1 if col < 0 else x - 1

    da = ""
    la = ""
    ra = ""
    ua = ""

    dcnt = min(down_cnt * 2, rest_cnt)
    da += "d" * (dcnt // 2)
    ua += "u" * (dcnt // 2)
    rest_cnt -= dcnt

    if row > 0:
        da += "d" * rcnt
    else:
        ua += "u" * rcnt

    lcnt = min(left_cnt * 2, rest_cnt)
    la += "l" * (lcnt // 2)
    ra += "r" * (lcnt // 2)
    rest_cnt -= lcnt

    if col < 0:
        la += "l" * ccnt
    else:
        ra += "r" * ccnt

    answer += da
    answer += la

    if rest_cnt > 0 and m > 1:
        answer += "rl" * (rest_cnt // 2)
        answer += ra
        answer += ua
    elif rest_cnt > 0:
        answer += ra
        answer += "ud" * (rest_cnt // 2)
        answer += ua
    else:
        answer += ra
        answer += ua

    return answer


print(solution(4, 4, 3, 1, 2, 3, 7))

"""
. . . .
. . E .
S . . .
. . . .

drlrluu
"""
