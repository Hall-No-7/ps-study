def canInstall(frame, x, y, case, n):
    if case == 0:
        if y == 0:
            return True
        elif frame[1][y][x] or (x >= 1 and frame[1][y][x - 1]):
            return True
        elif y >= 1 and frame[0][y - 1][x]:
            return True
    else:
        if y >= 1 and frame[0][y - 1][x] or (x + 1 <= n and frame[0][y - 1][x + 1]):
            return True
        elif (x >= 1 and frame[1][y][x - 1]) and (x + 1 <= n and frame[1][y][x + 1]):
            return True
    return False


def canDelete(frame, x, y, case, n):
    tmp = [[row[:] for row in frame[i]] for i in range(2)]
    tmp[case][y][x] = 0
    if case == 0:
        if y + 1 <= n and tmp[0][y + 1][x] and not canInstall(tmp, x, y + 1, 0, n):
            return False
        elif (
            y + 1 <= n
            and ((tmp[1][y + 1][x] and not canInstall(tmp, x, y + 1, 1, n)) 
            or (x >= 1 and tmp[1][y + 1][x - 1] and not canInstall(tmp, x - 1, y + 1, 1, n)))
        ):
            return False
    else:
        if x + 1 <= n and tmp[0][y][x + 1] and not canInstall(tmp, x + 1, y, 0, n):
            return False
        elif tmp[0][y][x] and not canInstall(tmp, x, y, 0, n):
            return False
        elif (
            (x + 1 <= n and tmp[1][y][x + 1] and not canInstall(tmp, x + 1, y, 1, n))
            or (x >= 1 and tmp[1][y][x - 1] and not canInstall(tmp, x - 1, y, 1, n))
        ):
            return False
    return True


def solution(n, build_frame):
    answer = []
    
    frame = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(2)]
    for x, y, a, b in build_frame:
        if b == 0 and canDelete(frame, x, y, a, n):
            frame[a][y][x] = 0                
        elif b == 1 and canInstall(frame, x, y, a, n):
            frame[a][y][x] = 1
    
    for x in range(n + 1):
        for y in range(n + 1):
            for i in range(2):
                if frame[i][y][x]:
                    answer.append((x, y, i))
    
    return answer
