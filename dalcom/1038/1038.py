from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/1038/input.txt", "rt")

n = int(input.readline())
nums = [i for i in range(10)]
lst = []


def combination(depth, level, limit, result):
    global lst
    if depth == limit:
        lst.append(result)
        return

    for i in range(level - 1, -1, -1):
        combination(depth + 1, i, limit, result * 10 + i)


def solution():
    global lst
    for i in range(1, 11):
        combination(0, 10, i, 0)
    lst = sorted(lst)

    if n >= len(lst):
        return -1
    return lst[n]


print(solution())
