from collections import deque

N = 0
xy = [(0, -1), (1, 0), (0, 1), (-1, 0)]


def check(board, x, y):
    if x < 0 or x >= N or y < 0 or y >= N:
        return False
    if board[y][x] == 1:
        return False
    return True


def can_move(board, fp, sp):
    result = []

    is_lie = True if fp[0] == sp[0] else False

    # 상하좌우
    for x, y in xy:
        rr1, rr2 = fp[0] + y, sp[0] + y
        cc1, cc2 = fp[1] + x, sp[1] + x

        if check(board, cc1, rr1) and check(board, cc2, rr2):
            result.append({(rr1, cc1), (rr2, cc2)})

    # 회전
    if is_lie:
        if fp[0] > 0 and (
            board[fp[0] - 1][fp[1]] == 0 and board[sp[0] - 1][sp[1]] == 0
        ):
            result.append({(fp[0] - 1, fp[1]), (fp[0], fp[1])})
            result.append({(sp[0] - 1, sp[1]), (sp[0], sp[1])})

        if fp[0] < N - 1 and (
            board[fp[0] + 1][fp[1]] == 0 and board[sp[0] + 1][sp[1]] == 0
        ):
            result.append({(fp[0], fp[1]), (fp[0] + 1, fp[1])})
            result.append({(sp[0], sp[1]), (sp[0] + 1, sp[1])})
    else:
        if fp[1] > 0 and (
            board[fp[0]][fp[1] - 1] == 0 and board[sp[0]][sp[1] - 1] == 0
        ):
            result.append({(fp[0], fp[1] - 1), (fp[0], fp[1])})
            result.append({(sp[0], sp[1] - 1), (sp[0], sp[1])})
        if fp[1] < N - 1 and (
            board[fp[0]][fp[1] + 1] == 0 and board[sp[0]][sp[1] + 1] == 0
        ):
            result.append({(fp[0], fp[1]), (fp[0], fp[1] + 1)})
            result.append({(sp[0], sp[1]), (sp[0], sp[1] + 1)})

    return result


def solution(board):
    global N
    N = len(board)
    answer = 0

    dq = deque()
    visited = []

    dq.append([{(0, 0), (0, 1)}, 1])
    visited.append({(0, 0), (0, 1)})

    while dq:
        p, dist = dq.popleft()
        fp, sp = list(p)[0], list(p)[1]

        for p1, p2 in can_move(board, fp, sp):
            if (N - 1, N - 1) == p1 or (N - 1, N - 1) == p2:
                return dist
            if {p1, p2} in visited:
                continue
            visited.append({p1, p2})
            dq.append([{p1, p2}, dist + 1])

    return answer


print(
    solution(
        [
            [0, 0, 0, 1, 1],
            [0, 0, 0, 1, 0],
            [0, 1, 0, 1, 1],
            [1, 1, 0, 0, 1],
            [0, 0, 0, 0, 0],
        ]
    )
)
