def convert(n, k):
    ret = ""
    while n > 0:
        ret = str(n % k) + ret
        n //= k
    return ret


def is_prime(n):
    if n <= 1:
        return False
    
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


def solution(n, k):
    answer = 0
    
    n = convert(n, k)
    for x in n.split("0"):
        if x != "" and is_prime(int(x)):
            answer += 1
    
    return answer
