from collections import deque

yx = [(-1, 0, "UD"), (1, 0, "UD"), (0, 1, "LR"), (0, -1, "LR")]


def calc_cost(prev_d, cur_d):
    if prev_d == cur_d:
        return 100
    else:
        return 600


def bfs(board):
    n = len(board)
    dq = deque([(0, 0, 0, "UD")])
    dq.append((0, 0, 0, "LR"))

    visited = [[0 for _ in range(n)] for _ in range(n)]
    visited[0][0] = 1

    while len(dq):
        r, c, cost, dir = dq.popleft()

        for y, x, d in yx:
            yy = y + r
            xx = x + c
            if yy < 0 or yy >= n or xx < 0 or xx >= n:
                continue
            if board[yy][xx] == 1:
                continue

            new_cost = cost + calc_cost(dir, d)
            if visited[yy][xx] and visited[yy][xx] < new_cost:
                continue
            visited[yy][xx] = new_cost
            dq.append([yy, xx, new_cost, d])
    return visited[n - 1][n - 1]


def solution(board):
    answer = 0

    answer = bfs(board)
    return answer


print(solution([[0, 0, 1, 0], [0, 0, 0, 0], [0, 1, 0, 1], [1, 0, 0, 0]]))
