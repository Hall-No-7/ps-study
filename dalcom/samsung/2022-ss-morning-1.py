class Player:
    def __init__(self, idx, r, c, dir):
        self.id = idx
        self.r = r
        self.c = c
        self.dir = dir  # up: 0 down: 2 left: 1 right: 3
        self.die = False


class Boss:
    def __init__(self, r, c):
        self.r = r
        self.c = c
        self.idx = 0
        self.dir = -1
        self.is_front = True
        self.front_root = []
        self.back_root = []
        self.score = 0


def create_boss_root(boss: Boss):
    visited = [[False for _ in range(N)] for _ in range(N)]
    d_idx = 0
    dirs = [2, 3, 0, 1]
    r, c = 0, 0
    result = [(r, c, dirs[d_idx])]
    check = []
    visited[r][c] = True

    for i in range(N * N - 1):
        rr = r + d4[dirs[d_idx]][0]
        cc = c + d4[dirs[d_idx]][1]

        if rr < 0 or rr >= N or cc < 0 or cc >= N:
            d_idx = (d_idx + 1) % 4
            rr = r + d4[dirs[d_idx]][0]
            cc = c + d4[dirs[d_idx]][1]
            check.append((i, r, c, dirs[d_idx]))

        if visited[rr][cc]:
            d_idx = (d_idx + 1) % 4
            rr = r + d4[dirs[d_idx]][0]
            cc = c + d4[dirs[d_idx]][1]
            check.append((i, r, c, dirs[d_idx]))

        visited[rr][cc] = True
        result.append((rr, cc, dirs[d_idx]))
        r = rr
        c = cc

    boss.back_root = result
    rev_result = result[::-1]

    for item in rev_result:
        r, c, dir = item
        dir = (dir + 2) % 4
        boss.front_root.append((r, c, dir))

    for item in check:
        idx, r, c, dir = item
        boss.back_root[idx] = (r, c, dir)


def calc_distance(r1, r2, c1, c2):
    return abs(r1 - r2) + abs(c1 - c2)


def move_player(player: Player):
    if player.die:
        return

    dis = calc_distance(player.r, boss.r, player.c, boss.c)
    if dis > 3:
        return

    rr = player.r + d4[player.dir][0]
    cc = player.c + d4[player.dir][1]

    if rr < 0 or rr >= N or cc < 0 or cc >= N:
        player.dir = (player.dir + 2) % 4
        rr = player.r + d4[player.dir][0]
        cc = player.c + d4[player.dir][1]

    if boss.r == rr and boss.c == cc:
        return

    player.r = rr
    player.c = cc


def move_boss(boss: Boss):
    boss.idx = boss.idx + 1

    rr, cc, dir = -1, -1, -1
    if boss.is_front:
        rr, cc, dir = boss.front_root[boss.idx]
    if not boss.is_front:
        rr, cc, dir = boss.back_root[boss.idx]
    boss.r = rr
    boss.c = cc
    boss.dir = dir

    if boss.idx == (N*N) - 1:
        boss.is_front = not boss.is_front
        boss.idx = 0
        boss.dir = (boss.dir + 2) % 4


def boss_action(boss: Boss, t):
    catch_cnt = 0
    b_r = boss.r
    b_c = boss.c

    find_range = [(b_r, b_c)]

    for _ in range(2):
        rr = b_r + d4[boss.dir][0]
        cc = b_c + d4[boss.dir][1]

        if rr < 0 or rr >= N or cc < 0 or cc >= N:
            continue
        find_range.append((rr, cc))
        b_r = rr
        b_c = cc

    for r, c in find_range:
        if board[r][c] == 1:
            continue
        for player in players:
            if player.die:
                continue
            if player.r == r and player.c == c:
                catch_cnt += 1
                player.die = True

    boss.score += t * catch_cnt


def game_over():
    for player in players:
        if not player.die:
            return False
    return True


def calc_dir(dir):
    if dir == 0:
        return 'U'
    elif dir == 1:
        return 'L'
    elif dir == 2:
        return 'D'
    elif dir == 3:
        return 'R'
    else:
        return 'I'

def print_boss():
    for _ in range(N*N*2):
        print(f"가 -> 꼭 {boss.is_front}")
        for i in range(N):
            for j in range(N):
                if boss.r == i and boss.c == j:
                    print(f"B{calc_dir(boss.dir)}", end= ' ')
                else:
                    print("0", end=' ')
            print()
        move_boss(boss)
        print("\n\n")


d4 = [(-1, 0), (0, -1), (1, 0), (0, 1)]

N, M, H, K = map(int, input().split())
board = [[0 for _ in range(N)] for _ in range(N)]  # tree: 1
players = []
center = (N // 2, N // 2)
top_corner = (0, 0)
boss = Boss(N // 2, N // 2)
create_boss_root(boss)

for i in range(M):
    r, c, dir = map(int, input().split())
    if dir == 1:
        new_player = Player(i, r - 1, c - 1, 3)
        players.append(new_player)
    else:
        new_player = Player(i, r - 1, c - 1, 2)
        players.append(new_player)

for _ in range(H):
    r, c = map(int, input().split())
    board[r - 1][c - 1] = 1

for t in range(1, K + 1):
    for player in players:
        move_player(player)
    move_boss(boss)
    boss_action(boss, t)

    if game_over():
        break

print(boss.score)
