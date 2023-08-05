class Node:
    def __init__(self, g, b):
        self.g = g
        self.b = b


def checkRule(board, x, y, a, b):
    if a == 0 and b == 1:
        if y == 0:
            return True
        if board[y - 1][x].g:
            return True
        elif board[y][x - 1].b or board[y][x].b:
            return True
        return False

    if a == 1 and b == 1:
        if board[y - 1][x].g or board[y - 1][x + 1].g:
            return True
        if board[y][x - 1].b and board[y][x + 1].b:
            return True
        return False

    if a == 0 and b == 0:
        board[y][x].g = False

        l, r, u = True, True, True

        if board[y + 1][x].g:
            u = checkRule(board, x, y + 1, 0, 1)
        if x - 1 >= 0 and board[y + 1][x - 1].b:
            l = checkRule(board, x - 1, y + 1, 1, 1)
        if board[y + 1][x].b:
            r = checkRule(board, x, y + 1, 1, 1)

        board[y][x].g = True
        if l and r and u:
            return True
        else:
            return False

    if a == 1 and b == 0:
        board[y][x].b = False

        l, ul, ur, r = True, True, True, True

        if board[y][x].g:
            ul = checkRule(board, x, y, 0, 1)
        if board[y][x + 1].g:
            ur = checkRule(board, x + 1, y, 0, 1)
        if x - 1 >= 0 and board[y][x - 1].b:
            l = checkRule(board, x - 1, y, 1, 1)
        if board[y][x + 1].b:
            r = checkRule(board, x + 1, y, 1, 1)

        board[y][x].b = True
        if l and r and ul and ur:
            return True
        else:
            return False


def solution(n, build_frame):
    answer = []

    board = [[Node(False, False) for _ in range(1004)] for _ in range(1004)]

    for x, y, a, b in build_frame:
        x = x + 1
        y = y
        if checkRule(board, x, y, a, b):
            if b == 1:
                if a == 0:
                    board[y][x].g = True
                if a == 1:
                    board[y][x].b = True
            elif b == 0:
                if a == 0:
                    board[y][x].g = False
                if a == 1:
                    board[y][x].b = False

    for i in range(len(build_frame) + 1):
        for j in range(len(build_frame) + 1):
            if board[i][j].g:
                answer.append([j - 1, i, 0])
            if board[i][j].b:
                answer.append([j - 1, i, 1])

    return sorted(answer, key=lambda x: (x[0], x[1]))
