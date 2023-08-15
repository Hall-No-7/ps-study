from collections import defaultdict
import math


def calc_time(time_a, time_b):
    h_a, m_a = map(int, time_a.split(":"))
    h_b, m_b = map(int, time_b.split(":"))

    return abs((h_b * 60 + m_b) - (h_a * 60 + m_a))


def solution(fees, records):
    answer = []
    base_time, base_fee, div_min, mul_fee = fees

    in_dict = defaultdict(list)
    out_dict = defaultdict(list)

    for record in records:
        time, num, cmd = record.split()
        if cmd == "IN":
            in_dict[num].append(time)
        else:
            out_dict[num].append(time)

    for car_num in sorted(in_dict.keys(), key=lambda x: x):
        time = 0
        for p in range(len(in_dict[car_num])):
            in_time = in_dict[car_num][p]
            out_time = out_dict[car_num][p] if p < len(out_dict[car_num]) else "23:59"

            time += calc_time(in_time, out_time)

        result_fee = base_fee

        if time > base_time:
            result_fee += int(math.ceil((time - base_time) / div_min)) * mul_fee

        answer.append(result_fee)

    return answer
