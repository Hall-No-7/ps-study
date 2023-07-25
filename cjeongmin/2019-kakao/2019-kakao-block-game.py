def findTargetBlock(board):   
    visited = set()
    for y in range(len(board)):
        for x in range(len(board)):
            if board[y][x] == 0 or (y, x) in visited:
                continue
            blocks = sorted(findBlocks(board, board[y][x], y, x))
            visited |= {*blocks}
            
            xarray, yarray = list(map(lambda x: x[1], blocks)), list(map(lambda x: x[0], blocks))
            xlo, xhi = min(xarray), max(xarray)
            ylo, r = min(yarray), max(yarray)
            for c in range(xlo, xhi + 1):
                if board[r][c] != board[y][x]:
                    break
                    
                offset = 0
                while board[r - offset - 1][c] == board[r][c]:
                    offset += 1
                    
                if r - offset == ylo:
                    continue
                
                offset += 1
                while r >= offset:
                    if board[r - offset][c] != 0:
                        break
                    offset += 1
                else:
                    continue
                break
            else:
                return blocks
    return None


def findBlocks(board, target, y, x):
    ret = [(y, x)]
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]
    
    board[y][x] *= -1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if not (0 <= nx < len(board) and 0 <= ny < len(board)):
            continue
        if board[ny][nx] != target:
            continue
        ret += findBlocks(board, target, ny, nx)
    board[y][x] *= -1
    return ret
    


def solution(board):
    answer = 0
    
    while True:
        block = findTargetBlock(board)
        if block is None:
            break
        
        for y, x in block:
            board[y][x] = 0
        answer += 1
    
    return answer
