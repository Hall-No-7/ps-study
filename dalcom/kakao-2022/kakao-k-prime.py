def is_prime(num):
    if num < 2:
        return False

    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


def trans_num(n, k):
    result = ""
    while n >= k:
        result += str(n % k)
        n = n // k
    result += str(n)
    return result[::-1]


def solution(n, k):
    answer = 0

    str_num = trans_num(n, k)
    num_lst = str_num.split("0")

    for i in num_lst:
        if i.isdigit():
            if is_prime(int(i)):
                answer += 1

    return answer
