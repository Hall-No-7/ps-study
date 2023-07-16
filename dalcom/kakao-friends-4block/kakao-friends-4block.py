from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/friends-4block/input.txt", "rt")
yx = [(0, 0), (0, 1), (1, 0), (1, 1)]


def check(visited, board, p, m, n):
    for y, x in yx:
        yy = p[0] + y
        xx = p[1] + x
        if yy < 0 or yy >= m or xx < 0 or xx >= n:
            return 0
        if board[yy][xx] == board[p[0]][p[1]]:
            continue
        else:
            return 0

    result = 0
    for y, x in yx:
        yy = p[0] + y
        xx = p[1] + x
        if not visited[yy][xx]:
            result += 1
        visited[yy][xx] = True
    return result


def erase(board, visited, m, n):
    for c in range(n):
        info = []
        cnt = 0
        for r in range(m):
            if visited[r][c]:
                board[r][c] = " "
                visited[r][c] = False

        for r in range(m - 1, -1, -1):
            if board[r][c] == " ":
                cnt += 1
            elif cnt > 0:
                info.append((r, cnt))

        for y, diff in info:
            board[y + diff][c] = board[y][c]
            board[y][c] = " "


def solution(m, n, board):
    answer = 0
    board = [list(board[i]) for i in range(len(board))]
    visited = [[False for _ in range(n)] for _ in range(m)]
    done = False

    while done == False:
        done = True
        for i, row in enumerate(board):
            for j, val in enumerate(row):
                if val == " ":
                    continue
                res = check(visited, board, (i, j), m, n)
                if res != 0:
                    done = False
                answer += res

        if done == False:
            erase(board, visited, m, n)

    return answer


n, m = map(int, input.readline().split())
board = []
for _ in range(m):
    board.append(input.readline())

print(solution(6, 6, board))
