from sys import stdin as input
from collections import deque
input = open("/Volumes/Program/ps-study/dalcom/16197/input.txt", "rt")

n, m = map(int, input.readline().split())

board = []
cs = []
yx = [(-1, 0), (0, 1), (1, 0), (0, -1)]

for i in range(n):
    inputs = list(input.readline())
    board.append(inputs)
    for j, val in enumerate(inputs):
        if val == 'o':
            cs.append((i, j))


def bfs():
    dq = deque([(cs, 0)])
    while len(dq) > 0:
        cp, dist = dq.popleft()

        if dist >= 10:
            return -1

        for y, x in yx:
            p1 = (y + cp[0][0], x + cp[0][1])
            p2 = (y + cp[1][0], x + cp[1][1])
            if (p1[0] < 0 or p1[0] >= n or p1[1] < 0 or p1[1] >= m) and (p2[0] < 0 or p2[0] >= n or p2[1] < 0 or p2[1] >= m):
                continue
            if (p1[0] < 0 or p1[0] >= n or p1[1] < 0 or p1[1] >= m):
                return dist + 1
            if (p2[0] < 0 or p2[0] >= n or p2[1] < 0 or p2[1] >= m):
                return dist + 1
            if (board[p1[0]][p1[1]] == '#') and (board[p2[0]][p2[1]] == '#'):
                continue
            if board[p1[0]][p1[1]] == '#':
                p1 = (cp[0][0], cp[0][1])
            if board[p2[0]][p2[1]] == '#':
                p2 = (cp[1][0], cp[1][1])
            dq.append(([p1, p2], dist + 1))
    return -1


print(bfs())
