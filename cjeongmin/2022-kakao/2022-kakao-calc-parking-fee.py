from math import ceil
from collections import defaultdict


def convert(time):
    time = time.split(":")
    return int(time[0]) * 60 + int(time[1])


def solution(fees, records):
    answer = []
    
    time_per_number = defaultdict(int)
    enter = {}
    for time, number, case in map(lambda v: v.split(), records):
        time = convert(time)
        if case == "IN":
            enter[number] = time
        else:
            enter_time = enter[number]
            time_per_number[number] += time - enter_time
            enter.pop(number)
    
    for number in enter:
        time_per_number[number] += convert("23:59") - enter[number]
            
    for number, time in sorted(time_per_number.items()):
        price = fees[1]
        if time > fees[0]:
            price += ceil((time - fees[0]) / fees[2]) * fees[3]
        answer.append(price)
        
    return answer
