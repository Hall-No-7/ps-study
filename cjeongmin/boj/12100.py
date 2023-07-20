from sys import stdin

input = lambda: stdin.readline().rstrip()


def dfs(board: list[list[int]], depth: int) -> int:
    if depth == 5:
        return max(map(lambda x: max(x), board))

    depth += 1
    return max(
        dfs(move_left(board), depth),
        dfs(move_up(board), depth),
        dfs(move_right(board), depth),
        dfs(move_down(board), depth),
    )


def move_left(board: list[list[int]]) -> list[list[int]]:
    new_board = copy(board)

    combined: set[tuple[int, int]] = set()
    for r in range(N):
        for c in range(1, N):
            if new_board[r][c] == 0:
                continue

            c -= 1
            while c >= 0 and new_board[r][c] == 0:
                new_board[r][c] = new_board[r][c + 1]
                new_board[r][c + 1] = 0
                if c > 0:
                    c -= 1
                else:
                    break

            if (r, c) not in combined and new_board[r][c] == new_board[r][c + 1]:
                new_board[r][c] *= 2
                new_board[r][c + 1] = 0
                combined |= {(r, c)}

    return new_board


def move_up(board: list[list[int]]) -> list[list[int]]:
    new_board = copy(board)

    combined: set[tuple[int, int]] = set()
    for c in range(N):
        for r in range(1, N):
            if new_board[r][c] == 0:
                continue

            r -= 1
            while r >= 0 and new_board[r][c] == 0:
                new_board[r][c] = new_board[r + 1][c]
                new_board[r + 1][c] = 0
                if r > 0:
                    r -= 1
                else:
                    break

            if (r, c) not in combined and new_board[r][c] == new_board[r + 1][c]:
                new_board[r][c] *= 2
                new_board[r + 1][c] = 0
                combined |= {(r, c)}

    return new_board


def move_right(board: list[list[int]]) -> list[list[int]]:
    new_board = copy(board)

    combined: set[tuple[int, int]] = set()
    for r in range(N):
        for c in range(N - 2, -1, -1):
            if new_board[r][c] == 0:
                continue

            c += 1
            while c < N and new_board[r][c] == 0:
                new_board[r][c] = new_board[r][c - 1]
                new_board[r][c - 1] = 0
                if c + 1 < N:
                    c += 1
                else:
                    break

            if (r, c) not in combined and new_board[r][c] == new_board[r][c - 1]:
                new_board[r][c] *= 2
                new_board[r][c - 1] = 0
                combined |= {(r, c)}

    return new_board


def move_down(board: list[list[int]]) -> list[list[int]]:
    new_board = copy(board)

    combined: set[tuple[int, int]] = set()
    for c in range(N):
        for r in range(N - 2, -1, -1):
            if new_board[r][c] == 0:
                continue

            r += 1
            while r < N and new_board[r][c] == 0:
                new_board[r][c] = new_board[r - 1][c]
                new_board[r - 1][c] = 0
                if r + 1 < N:
                    r += 1
                else:
                    break

            if (r, c) not in combined and new_board[r][c] == new_board[r - 1][c]:
                new_board[r][c] *= 2
                new_board[r - 1][c] = 0
                combined |= {(r, c)}

    return new_board


def copy(board: list[list[int]]) -> list[list[int]]:
    return [row[:] for row in board]


N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
print(dfs(board, 0))
