class Player:
    def __init__(self, idx, r, c, d, pw):
        self.id = idx
        self.r = r
        self.c = c
        self.dir = d
        self.init_power = pw
        self.gun = 0
        self.score = 0

    def __str__(self):
        return f"참가자{self.id} ({self.r}, {self.c}) {self.init_power} {self.gun}"


def move_player(player: Player):
    rr = player.r + d4[player.dir][0]
    cc = player.c + d4[player.dir][1]

    if rr < 0 or rr >= N or cc < 0 or cc >= N:
        player.dir = (player.dir + 2) % 4
        rr = player.r + d4[player.dir][0]
        cc = player.c + d4[player.dir][1]

    player.r = rr
    player.c = cc

    has_player = False
    oth_player = None
    for p in players:
        if p.id == player.id:
            continue
        if p.r == player.r and p.c == player.c:
            has_player = True
            oth_player = p
            break

    if not has_player:
        check_and_get_gun(player)
    else:
        fighting(player, oth_player)


def check_and_get_gun(player: Player):
    if max(board[player.r][player.c]) == 0:
        return

    target = max(board[player.r][player.c])
    if player.gun >= target:
        return

    for idx, gun in enumerate(board[player.r][player.c]):
        if target == gun:
            tmp_gun = player.gun
            player.gun = gun
            board[player.r][player.c][idx] = tmp_gun


def fighting(player1: Player, player2: Player):
    p1_score = player1.init_power + player1.gun
    p2_score = player2.init_power + player2.gun

    winner = None
    loser = None

    if p1_score > p2_score:
        winner = player1
        loser = player2
    elif p1_score < p2_score:
        winner = player2
        loser = player1
    else:
        if player1.init_power > player2.init_power:
            winner = player1
            loser = player2
        else:
            winner = player2
            loser = player1

    # 2-2-1
    winner.score += abs(p1_score - p2_score)

    # 2-2-2
    board[loser.r][loser.c].append(loser.gun)
    loser.gun = 0

    loser_move = False
    for i in range(4):
        rr = loser.r + d4[(loser.dir + i) % 4][0]
        cc = loser.c + d4[(loser.dir + i) % 4][1]

        if rr < 0 or rr >= N or cc < 0 or cc >= N:
            continue

        flag = True
        for player in players:
            if loser.id == player.id:
                continue
            if rr == player.r and cc == player.c:
                flag = False
                break
        if not flag:
            continue

        loser.r = rr
        loser.c = cc
        loser.dir = (loser.dir + i) % 4
        loser_move = True
        break

    if loser_move:
        check_and_get_gun(loser)

    # 2-2-3
    check_and_get_gun(winner)


def print_board():
    for i in range(N):
        for j in range(N):
            print(board[i][j], end=' ')
        print()


def convert_dir(dir):
    if dir == 0:
        return 'U'
    elif dir == 1:
        return 'R'
    elif dir == 2:
        return 'D'
    else:
        return 'L'


def print_players():
    for i in range(N):
        for j in range(N):
            flag = True
            for player in players:
                if player.r == i and player.c == j:
                    print(f"{player.id}{convert_dir(player.dir)}", end=' ')
                    flag = False
                    break
            if flag:
                print(0, end=' ')
        print()
    print("\n\n")


d4 = [(-1, 0), (0, 1), (1, 0), (0, -1)]

N, M, K = map(int, input().split())
input_board = [list(map(int, input().split())) for _ in range(N)]
board = [[[] for _ in range(N)] for _ in range(N)]
players = []

for i in range(N):
    for j in range(N):
        board[i][j].append(input_board[i][j])

for i in range(M):
    R, C, D, S = map(int, input().split())
    players.append(Player(i, R - 1, C - 1, D, S))

for _ in range(K):
    for player in players:
        move_player(player)

for player in players:
    print(player.score, end=' ')
