from sys import stdin as input
from datetime import datetime, timedelta


def solution(lines):
    answer = 0
    data = []
    for line in lines:
        date, time, diff = line.split()
        dt = datetime.strptime(date + " " + time, "%Y-%m-%d %H:%M:%S.%f")
        diff = diff[:-1].split(".")
        ms = int(diff[0]) * 1000
        if len(diff) == 2:
            ms += int(diff[1])

        data.append((dt - timedelta(milliseconds=ms - 1), dt))

    for i, (startA, endA) in enumerate(data):
        cnt = 1
        for startB, endB in data[i + 1 :]:
            if (
                startA - timedelta(milliseconds=999) <= endB
                and endA + timedelta(milliseconds=999) >= startB
            ):
                cnt += 1
        answer = max(answer, cnt)

    return answer
