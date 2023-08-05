from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/15661/input.txt", "rt")

n = int(input.readline())
score = []

for _ in range(n):
    score.append(list(map(int, input.readline().split())))

result = 1 << 31


def calc_score(arr):
    st, lt = 0, 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            if arr[i] and arr[j]:
                st += score[i][j] + score[j][i]
            elif not arr[i] and not arr[j]:
                lt += score[i][j] + score[j][i]
    return abs(st - lt)


def recur(depth, t):
    global result
    if depth == n:
        result = min(result, calc_score(t))
        return

    t[depth] = True
    recur(depth + 1, t)
    t[depth] = False
    recur(depth + 1, t)


recur(0, [False for _ in range(n)])
print(result)
