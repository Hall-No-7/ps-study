from collections import deque


class Basecamp:
    def __init__(self, r, c):
        self.r = r
        self.c = c
        self.used = False


class Conv:
    def __init__(self, idx, r, c):
        self.id = idx
        self.r = r
        self.c = c
        self.closed = False

    def __str__(self):
        return f"편의점 ({self.r}, {self.c})"


class Player:
    def __init__(self, idx, r, c, conv: Conv):
        self.id = idx
        self.r = r
        self.c = c
        self.conv = conv
        self.in_board = False
        self.done = False

    def __str__(self):
        return f"참가자{self.id} ({self.r}, {self.c}) | 완료 {self.done} | 출발 {self.in_board} | {self.conv}"


def condition_1(player: Player):
    if player.done or not player.in_board:
        return

    i_dir = -1

    visited = [[False for _ in range(N)] for _ in range(N)]
    queue = deque()
    queue.append((player.r, player.c, -1))
    visited[player.r][player.c] = True

    while queue:
        r, c, init_dir = queue.popleft()

        if r == player.conv.r and c == player.conv.c:
            i_dir = init_dir
            break

        for i, d in enumerate(d4):
            rr = r + d[0]
            cc = c + d[1]

            if rr < 0 or rr >= N or cc < 0 or cc >= N:
                continue
            if visited[rr][cc]:
                continue
            if board[rr][cc] == 1 and b_camp_board[rr][cc].used:
                continue
            if board[rr][cc] == 2 and conv_board[rr][cc].closed:
                continue
            visited[rr][cc] = True
            if init_dir == -1:
                queue.append((rr, cc, i))
            else:
                queue.append((rr, cc, init_dir))

    player.r += d4[i_dir][0]
    player.c += d4[i_dir][1]


def condition_2(player: Player):
    if player.done or not player.in_board:
        return

    if player.r == player.conv.r and player.c == player.conv.c:
        player.done = True
        player.conv.closed = True


def condition_3(player: Player):
    if player.done or player.in_board:
        return

    visited = [[False for _ in range(N)] for _ in range(N)]
    queue = deque()
    for i, basecamp in enumerate(basecamps):
        if basecamp.used:
            continue
        queue.append((basecamp.r, basecamp.c, i))
        visited[basecamp.r][basecamp.c] = True

    while queue:
        r, c, idx = queue.popleft()

        if r == player.conv.r and c == player.conv.c:
            player.in_board = True
            player.r = basecamps[idx].r
            player.c = basecamps[idx].c
            basecamps[idx].used = True
            return

        for d in d4:
            rr = r + d[0]
            cc = c + d[1]

            if rr < 0 or rr >= N or cc < 0 or cc >= N:
                continue
            if visited[rr][cc]:
                continue
            if board[rr][cc] == 1 and b_camp_board[rr][cc].used:
                continue
            if board[rr][cc] == 2 and conv_board[rr][cc].closed:
                continue
            visited[rr][cc] = True
            queue.append((rr, cc, idx))


def game_over():
    for player in players:
        if not player.done:
            return False
    return True


d4 = [(-1, 0), (0, -1), (0, 1), (1, 0)]

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
basecamps = []
b_camp_board = [[None for _ in range(N)] for _ in range(N)]
conv_board = [[None for _ in range(N)] for _ in range(N)]
players = []

for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            b_cmp = Basecamp(i, j)
            b_camp_board[i][j] = b_cmp
            basecamps.append(b_cmp)

for i in range(M):
    r, c = map(int, input().split())
    conv = Conv(i, r - 1, c - 1)
    conv_board[r - 1][c - 1] = conv
    players.append(Player(i, -1, -1, conv))
    board[r - 1][c - 1] = 2

t = -1
while True:
    t += 1
    ps = players[:min(t + 1, M)]

    for player in ps:
        condition_1(player)

    for player in ps:
        condition_2(player)

    for player in ps:
        condition_3(player)

    if game_over():
        break

print(t + 1)