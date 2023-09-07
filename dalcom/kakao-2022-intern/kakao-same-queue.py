from collections import deque


def solution(queue1, queue2):
    answer = 0

    q1_sum = sum(queue1)
    q2_sum = sum(queue2)

    n = len(queue1)
    m = len(queue2)

    if (q1_sum + q2_sum) % 2 != 0:
        return -1

    goal = (q1_sum + q2_sum) // 2

    queue1 = deque(queue1)
    queue2 = deque(queue2)

    while (n >= 0 or m >= 0) and q1_sum != goal:
        answer += 1
        if q1_sum < goal:
            q1_sum += queue2[0]
            q2_sum -= queue2[0]
            m -= 1
            queue1.append(queue2[0])
            queue2.popleft()
        else:
            q2_sum += queue1[0]
            q1_sum -= queue1[0]
            n -= 1
            queue2.append(queue1[0])
            queue1.popleft()

    if (n < 0 or m < 0) and q1_sum != goal:
        return -1
    return answer
