from collections import deque


def solution(board):
    N = len(board)
    robot = ((0, 0), (0, 1))
    queue = deque([(robot, 0)])
    visited = set([robot])
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]

    while len(queue):
        pos, count = queue.popleft()
        y1, x1 = pos[0]
        y2, x2 = pos[1]
        
        if (y1, x1) == (N-1, N-1) or (y2, x2) == (N-1, N-1):
            return count
        
        for i in range(4):
            ny1, nx1 = y1 + dy[i], x1 + dx[i]
            ny2, nx2 = y2 + dy[i], x2 + dx[i]
            
            if not (0 <= nx1 < N and 0 <= ny1 < N) or not (0 <= nx2 < N and 0 <= ny2 < N):
                continue
            if ((ny1, nx1), (ny2, nx2)) in visited:
                continue
            if board[ny1][nx1] or board[ny2][nx2]:
                continue
            
            queue.append((((ny1, nx1), (ny2, nx2)), count + 1))
            visited |= {((ny1, nx1), (ny2, nx2))}
            
        if y1 == y2:
            for v in [1, -1]:
                ny = y1 + v
                if 0 <= ny < N:
                    if board[ny][x2] == 0 and board[ny][x1] == 0 and ((y1, x1), (ny, x1)) not in visited:
                        visited |= {((y1, x1), (ny, x1))}
                        queue.append((((y1, x1), (ny, x1)), count + 1))
                    if board[ny][x1] == 0 and board[ny][x2] == 0 and ((y2, x2), (ny, x2)) not in visited:
                        visited |= {((y2, x2), (ny, x2))}
                        queue.append((((y2, x2), (ny, x2)), count + 1))
        elif x1 == x2:
            for v in [1, -1]:
                nx = x1 + v
                if 0 <= nx < N:
                    if board[y2][nx] == 0 and board[y1][nx] == 0 and ((y1, x1), (y1, nx)) not in visited:
                        visited |= {((y1, x1), (y1, nx))}
                        queue.append((((y1, x1), (y1, nx)), count + 1))
                    if board[y1][nx] == 0 and board[y2][nx] == 0 and ((y2, x2), (y2, nx)) not in visited:
                        visited |= {((y2, x2), (y2, nx))}
                        queue.append((((y2, x2), (y2, nx)), count + 1)) 

    return float("inf")
