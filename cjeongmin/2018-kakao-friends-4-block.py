def removeBlocks(m, n, board):
    blocks = set()
    for r in range(m-1):
        for c in range(n-1):
            if (
                board[r][c] != ''
                and board[r][c] == board[r][c+1]
                and board[r][c] == board[r+1][c]
                and board[r][c] == board[r+1][c+1]
            ):
                blocks |= {(r, c), (r, c+1), (r+1, c), (r+1, c+1)}
    for r, c in blocks:
        board[r][c] = ''
    return len(blocks)
    
def down(m, n, board):
    for r in range(m-1, -1, -1):
        for c in range(n):
            if board[r][c] == '':
                continue
            offset = 1
            while r+offset < m and board[r+offset][c] == '':
                board[r+offset][c] = board[r+offset-1][c]
                board[r+offset-1][c] = ''
                offset += 1

def solution(m, n, board):
    board = [list(row) for row in board]
    answer = 0
    while True:
        deletedBlockCount = removeBlocks(m, n, board)
        answer += deletedBlockCount
        if deletedBlockCount == 0:
            break
        down(m, n, board)
    return answer
