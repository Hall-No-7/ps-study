def is_prime(num: int):
    if num <= 1:
        return False

    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


def dfs(curr: str, depth: int):
    if depth == N:
        print(curr)
        return

    for i in range(1, 10):
        nxt = curr + str(i)
        if is_prime(int(nxt)):
            dfs(nxt, depth + 1)


N = int(input())
for i in range(2, 10):
    if is_prime(i):
        dfs(str(i), 1)
