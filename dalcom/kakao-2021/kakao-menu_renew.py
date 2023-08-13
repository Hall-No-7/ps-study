from itertools import combinations
from collections import defaultdict


def trans_bitmask(word):
    result = 0
    for ch in word:
        result += 1 << (ord(ch) - ord("A"))
    return result


def solution(orders, course):
    answer = []

    orders_bit = []
    comb_set = set()

    for order in orders:
        orders_bit.append(trans_bitmask(order))
        for cnt in course:
            for comb in combinations(order, cnt):
                comb_set.add("".join(sorted("".join(comb))))

    result = defaultdict(list)
    for menu in sorted(comb_set, key=lambda x: len(x)):
        menu_bit = trans_bitmask(menu)

        cnt = 0
        for order_bit in orders_bit:
            if menu_bit == (menu_bit & order_bit):
                cnt += 1

        if cnt >= 2:
            result[len(menu)].append((cnt, "".join(sorted("".join(menu)))))

    for item in result.values():
        max_cnt = max(item)[0]
        for cnt, word in item:
            if cnt == max_cnt:
                answer.append(word)

    return sorted(answer)
