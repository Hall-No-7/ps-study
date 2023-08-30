import math

possible = [2**x - 1 for x in range(1, 15)]


def check(binary, root):
    if root < 1:
        return True

    if sum(map(int, binary)) == 0:
        return True

    if binary[root] == "0":
        return False

    rt = (len(binary[:root]) - 1) // 2
    a = check(binary[:root], rt)
    b = check(binary[root + 1 :], rt)
    return a and b


def solution(numbers):
    answer = []
    for number in numbers:
        binary = format(number, "b")
        data = []
        if len(binary) not in possible:
            for pos in possible:
                if len(binary) < pos:
                    diff = pos - len(binary)
                    binary = "0" * diff + binary
                    break

        if check(binary, (len(binary) - 1) // 2):
            answer.append(1)
        else:
            answer.append(0)

    return answer


"""
1 3 7 ...

7 -> 111
42 -> 0111010
5 -> 101

10진수를 2진수로 변환한다

x = 2 ^ n - 1
x + 1 = 2 ^ n
log(x+1) = n

0001011 1 0001000
"""
