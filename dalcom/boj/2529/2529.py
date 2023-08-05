from sys import stdin as input
input = open("/Volumes/Program/ps-study/dalcom/2529/input.txt", "rt")

n = int(input.readline())
arr = list(input.readline().split())

selected = [False for _ in range(10)]
nums = []
max_result = '-1'
min_result = '999999999'


def check(left, right, idx):
    if left is None:
        return True
    if arr[idx] == '<' and left > right:
        return False
    if arr[idx] == '>' and left < right:
        return False
    return True


def recur(depth, left):
    global max_result, min_result
    if depth == n + 1:
        max_result = max(max_result, ''.join(list(map(str, nums))))
        min_result = min(min_result, ''.join(list(map(str, nums))))
        return

    for i in range(10):
        if not selected[i] and check(left, i, depth - 1):
            selected[i] = True
            nums.append(i)
            recur(depth + 1, i)
            selected[i] = False
            nums.pop()


recur(0, None)
print(max_result)
print(min_result)
