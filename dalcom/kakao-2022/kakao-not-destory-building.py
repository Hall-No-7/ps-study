def solution(board, skill):
    answer = 0

    attack = [[0 for _ in range(len(board[0]) + 2)] for _ in range(len(board) + 2)]
    defend = [[0 for _ in range(len(board[0]) + 2)] for _ in range(len(board) + 2)]
    result = [[] for _ in range(len(board))]

    for sk in skill:
        type, r1, c1, r2, c2, degree = sk
        if type == 1:
            attack[r1 + 1][c1 + 1] += degree
            attack[r2 + 2][c1 + 1] -= degree
            attack[r1 + 1][c2 + 2] -= degree
            attack[r2 + 2][c2 + 2] += degree
        else:
            defend[r1 + 1][c1 + 1] += degree
            defend[r2 + 2][c1 + 1] -= degree
            defend[r1 + 1][c2 + 2] -= degree
            defend[r2 + 2][c2 + 2] += degree

    for i in range(1, len(board) + 1):
        for j in range(1, len(board[0]) + 1):
            attack[i][j] += attack[i - 1][j] + attack[i][j - 1] - attack[i - 1][j - 1]
            defend[i][j] += defend[i - 1][j] + defend[i][j - 1] - defend[i - 1][j - 1]

            if board[i - 1][j - 1] + defend[i][j] - attack[i][j] > 0:
                answer += 1

    return answer


"""
[
[0 0 0 0]
[0 1 1 0]
[0 1 1 0]
[0 -1 0 1]
]
"""
