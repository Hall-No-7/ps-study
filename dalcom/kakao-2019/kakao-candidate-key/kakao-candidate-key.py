from itertools import combinations


def solution(relation):
    answer = 0
    tuple_cnt = len(relation)
    k = [i for i in range(len(relation[0]))]
    check = []

    for i in range(1, len(k) + 1):
        for ck in combinations(k, i):
            # 최소성 판단
            val = 0
            for n in ck:
                val += 1 << n
            for ch in check:
                if ch == (val & ch):
                    break
            else:
                s = set()
                # 유일성 판단
                for l in range(tuple_cnt):
                    item = ""
                    for m in ck:
                        item += relation[l][m]
                    s.add(item)
                if len(s) == tuple_cnt:
                    check.append(val)
                    answer += 1

    return answer
