from sys import stdin as input
input = open("/Volumes/Program/ps-study/dalcom/4574/input.txt", "rt")

dominos = []


def init():
    for i in range(1, 10):
        for j in range(i+1, 10):
            dominos.append(((i, j), False))


def sol(n):
    board = [[0 for _ in range(9)] for _ in range(9)]

    for _ in range(n):
        U, LU, V, LV = input.readline().split()
        board[ord(LU[0]) - ord('A')][int(LU[1]) - 1] = int(U)
        board[ord(LV[0]) - ord('A')][int(LV[1]) - 1] = int(V)

    inputs = list(input.readline().split())
    for i, LN in enumerate(inputs, 1):
        board[ord(LN[0]) - ord('A')][int(LN[1]) - 1] = i

    for row in board:
        print(row)


def main():
    init()
    while True:
        n = int(input.readline())
        if n == 0:
            break

        sol(n)


main()
