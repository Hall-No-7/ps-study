# r: 확인하고자 하는 행까지 위(0)에서부터 블록이 있는지 확인
def canFill(r, c, board):
    for i in range(r):
        if board[i][c]:
            return False
    return True


def canErase(r, c, board, h, w):
    emptyCnt = 0
    blockNum = -1

    for i in range(r, r + h):
        for j in range(c, c + w):
            if board[i][j] == 0:
                if not canFill(i, j, board):
                    return False
                emptyCnt += 1

                if emptyCnt > 2:
                    return False
            else:
                if blockNum == -1:
                    blockNum = board[i][j]
                elif blockNum != board[i][j]:
                    return False

    # 블록 지우기
    for i in range(r, r + h):
        for j in range(c, c + w):
            board[i][j] = 0

    return True


def solution(board):
    answer = 0

    while True:
        cnt = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if (
                    i <= len(board) - 2
                    and j <= len(board[0]) - 3
                    and canErase(i, j, board, 2, 3)
                ):
                    cnt += 1
                elif (
                    i <= len(board) - 3
                    and j <= len(board[0]) - 2
                    and canErase(i, j, board, 3, 2)
                ):
                    cnt += 1

        if cnt == 0:
            break
        answer += cnt

    return answer
