def scan(board, r, c, m, n):
    deleteMap = [[False for _ in range(n)] for __ in range(m)]
    rc_lis = [(r + 1, c), (r, c + 1), (r + 1, c + 1)]
    pivot = board[r][c]
    if pivot == "X":
        return False
    for _r, _c in rc_lis:
        if not ((0 <= _r < m) and (0 <= _c < n)):
            return False
        if pivot != board[_r][_c]:
            return False
    return True
        
def AllScan(board, m, n):
    del_rc_lis = set()
    for r in range(m):
        for c in range(n):
            if scan(board, r, c, m, n):
                del_rc_lis.add((r, c))
                del_rc_lis.add((r+1, c))
                del_rc_lis.add((r, c+1))
                del_rc_lis.add((r+1, c+1))
    return del_rc_lis

def updateMap(lis, board, m, n):
    _board = ["" for _ in range(m)]
    for r in range(m-1, -1, -1):
        line = []
        for c in range(n-1, -1, -1):
            s = "X"
            flag = True
            _r = r
            while (_r, c) in lis:
                _r -= 1
                if _r == -1:
                    flag = False
                    break
            if flag:
                s = board[_r][c]
                lis.add((_r, c))
            line.append(s)
        _board[r] = "".join(line)
    return _board
        

def solution(m, n, board):
    answer = 0
    
    while True:
        del_rc_lis = AllScan(board, m, n)
        if len(del_rc_lis) == 0:
            break
        answer += len(del_rc_lis)
        board = updateMap(del_rc_lis, board, m, n)
    
    return answer