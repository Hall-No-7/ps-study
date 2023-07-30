def put(x, y, M, key, board):
    for i in range(M):
        for j in range(M):
            board[x+i][y+j] += key[i][j]

def out(x, y, M, key, board):
    for i in range(M):
        for j in range(M):
            board[x+i][y+j] -= key[i][j]

def rotate(arr):
    return list(zip(*arr[::-1]))

def check(board, M, N):
    for i in range(N):
        for j in range(N):
            if board[M+i][M+j] != 1:
                return False
    return True

def solution(key, lock):
    M, N = len(key), len(lock)

    board = [[0] * (M*2 + N) for _ in range(M*2 + N)]
    for i in range(N):
        for j in range(N):
            board[M+i][M+j] = lock[i][j]

    r_key = key
    for _ in range(4):
        r_key = rotate(r_key)
        for x in range(1, M+N):
            for y in range(1, M+N):
                put(x, y, M, r_key, board)
                if(check(board, M, N)):
                    return True
                out(x, y, M, r_key, board)
                
    return False