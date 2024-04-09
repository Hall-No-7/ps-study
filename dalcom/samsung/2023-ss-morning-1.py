# 포탑 부수기

from collections import deque

n, m, k = list(map(int, input().split()))

board = [list(map(int, input().split())) for _ in range(n)]

destroyed = [[False for _ in range(m)] for _ in range(n)]

attack_his = [[0 for _ in range(m)] for _ in range(n)]

direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]
d8 = [(-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1)]


def check_destroyed():
    global destroyed
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                destroyed[i][j] = True


def select_weak_tower():
    result = [5001, -1, -1, 0]
    for i in range(n):
        for j in range(m):
            if destroyed[i][j]:
                continue
            if result[0] > board[i][j]:
                result = [board[i][j], i, j, attack_his[i][j]]
            elif result[0] == board[i][j]:
                if result[3] < attack_his[i][j]:
                    result = [board[i][j], i, j, attack_his[i][j]]
                elif result[3] == attack_his[i][j]:
                    if result[1] + result[2] < i + j:
                        result = [board[i][j], i, j, attack_his[i][j]]
                    elif result[1] + result[2] == i + j and result[2] < j:
                        result = [board[i][j], i, j, attack_his[i][j]]

    result[0] += n + m
    return result


def select_strong_tower():
    result = [0, 10, 10, 1001]
    for i in range(n):
        for j in range(m):
            if destroyed[i][j]:
                continue
            if result[0] < board[i][j]:
                result = [board[i][j], i, j, attack_his[i][j]]
            elif result[0] == board[i][j]:
                if result[3] > attack_his[i][j]:
                    result = [board[i][j], i, j, attack_his[i][j]]
                elif result[3] == attack_his[i][j]:
                    if result[1] + result[2] > i + j:
                        result = [board[i][j], i, j, attack_his[i][j]]
                    elif result[1] + result[2] == i + j and result[2] > j:
                        result = [board[i][j], i, j, attack_his[i][j]]

    return result


def can_move(ar, ac, tr, tc):
    visited = [[False for _ in range(m)] for _ in range(n)]
    queue = deque()
    queue.append((ar, ac, 0, list()))
    visited[ar][ac] = True

    while queue:
        r, c, dis, path = queue.popleft()

        if r == tr and c == tc:
            return path

        for i, (y, x) in enumerate(direction):
            rr = (r + y) % n
            cc = (c + x) % m

            if destroyed[rr][cc]:
                continue
            if visited[rr][cc]:
                continue
            visited[rr][cc] = True
            cp_path = [x for x in path]
            cp_path.append((rr, cc))
            queue.append((rr, cc, 1, cp_path))

    return []


def laser_attack(t, path, dmg, tr, tc, attack_range):
    global board, destroyed
    for r, c in path:
        board[r][c] = max(0, board[r][c] - dmg // 2)
        attack_range[r][c] = True
        if board[r][c] == 0:
            destroyed[r][c] = True

    board[tr][tc] = max(0, board[tr][tc] - dmg)
    attack_range[tr][tc] = True
    if board[tr][tc] == 0:
        destroyed[tr][tc] = True


def shell_attack(t, dmg, ar, ac, tr, tc, attack_range):
    global board, destroyed
    for y, x in d8:
        rr = (tr + y) % n
        cc = (tc + x) % m
        if destroyed[rr][cc]:
            continue
        if rr == ar and cc == ac:
            continue
        board[rr][cc] = max(0, board[rr][cc] - dmg // 2)
        attack_range[rr][cc] = True
        if board[rr][cc] == 0:
            destroyed[rr][cc] = True

    board[tr][tc] = max(0, board[tr][tc] - dmg)
    attack_range[tr][tc] = True
    if board[tr][tc] == 0:
        destroyed[tr][tc] = True


def repair_tower(t, attack_range):
    global board
    for i in range(n):
        for j in range(m):
            if destroyed[i][j]:
                continue
            if attack_range[i][j]:
                continue
            board[i][j] += 1


def check_all_destroyed():
    total = 0
    for i in range(n):
        total += sum(destroyed[i])
    if total == n * m - 1:
        return True
    return False


def print_board():
    for i in range(n):
        for j in range(m):
            print(board[i][j], end=' ')
        print()


def solution(t):
    global attack_his, board
    # [0]: dmg [1]: row [2]: col [3]: atk_his

    attack_range = [[False for _ in range(m)] for _ in range(n)]
    check_destroyed()

    if check_all_destroyed():
        return False

    attacker = select_weak_tower()
    target = select_strong_tower()

    board[attacker[1]][attacker[2]] += n + m
    path = can_move(attacker[1], attacker[2], target[1], target[2])
    if len(path) == 0:
        shell_attack(t, attacker[0], attacker[1], attacker[2], target[1], target[2], attack_range)
    else:
        path.pop()
        laser_attack(t, path, attacker[0], target[1], target[2], attack_range)

    attack_range[attacker[1]][attacker[2]] = True
    attack_his[attacker[1]][attacker[2]] = t

    repair_tower(t, attack_range)
    return True


for t in range(1, k + 1):
    if solution(t):
        continue
    break

result = 0
for i in range(n):
    for j in range(m):
        if destroyed[i][j]:
            continue
        result = max(result, board[i][j])

print(result)