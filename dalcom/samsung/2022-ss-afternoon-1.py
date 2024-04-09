from collections import deque


class Team:
    def __init__(self, idx):
        self.id = idx
        self.players = []
        self.root = deque()
        self.score = 0


class Player:
    def __init__(self, r, c):
        self.r = r
        self.c = c
        self.is_head = False
        self.is_tail = False

    def __str__(self):
        return f"참가자 ({self.r}, {self.c})"


def create_team_players(team: Team, head_player: Player):
    visited = [[False for _ in range(N)] for _ in range(N)]
    queue = deque()
    queue.append((head_player.r, head_player.c))
    visited[head_player.r][head_player.c] = True

    result = [head_player]
    tail_player = None
    while queue:
        r, c = queue.popleft()

        for d in d4:
            rr = r + d[0]
            cc = c + d[1]

            if rr < 0 or rr >= N or cc < 0 or cc >= N:
                continue
            if visited[rr][cc]:
                continue
            if board[rr][cc] == 2:
                visited[rr][cc] = True
                new_player = Player(rr, cc)
                result.append(new_player)
                queue.append((rr, cc))
            if board[rr][cc] == 3:
                visited[rr][cc] = True
                new_player = Player(rr, cc)
                new_player.is_tail = True
                tail_player = new_player

    result.append(tail_player)
    team.players = result


def create_team_root(team: Team):
    head_player = team.players[0]

    visited = [[False for _ in range(N)] for _ in range(N)]
    queue = deque()
    queue.append((head_player.r, head_player.c))
    visited[head_player.r][head_player.c] = True

    result = deque()

    while queue:
        r, c = queue.popleft()

        for d in d4:
            rr = r + d[0]
            cc = c + d[1]

            if rr < 0 or rr >= N or cc < 0 or cc >= N:
                continue
            if visited[rr][cc]:
                continue
            if board[rr][cc] == 4:
                visited[rr][cc] = True
                result.append((rr, cc))
                queue.append((rr, cc))

    for player in team.players[::-1]:
        if player.is_head:
            continue
        result.append((player.r, player.c))

    result.append((head_player.r, head_player.c))
    team.root = result


def reverse_team_player(team: Team):
    team.players[0].is_head = False
    team.players[0].is_tail = True
    team.players[-1].is_head = True
    team.players[-1].is_tail = False

    reverse_players = team.players[::-1]
    team.players = reverse_players


def reverse_team_root(team: Team):
    team_root = team.root
    for r, c in team_root:
        board[r][c] = 4

    for player in team.players:
        if player.is_head:
            board[player.r][player.c] = 1
            continue
        if player.is_tail:
            board[player.r][player.c] = 3
            continue
        board[player.r][player.c] = 2

    create_team_root(team)


def move_team_players(team: Team):
    front_r, front_c = -1, -1
    for player in team.players:
        if player.is_head:
            r, c = team.root.popleft()
            front_r = player.r
            front_c = player.c
            player.r = r
            player.c = c
            team.root.append((r, c))
        else:
            tmp_r = player.r
            tmp_c = player.c
            player.r = front_r
            player.c = front_c
            front_r = tmp_r
            front_c = tmp_c


def roll_ball(rn):
    rn = rn % (4 * N)
    r, c = -1, -1
    dir = -1

    if rn < N:
        r = rn
        c = 0
        dir = 1
    elif rn < 2*N:
        r = N - 1
        c = rn % N
        dir = 0
    elif rn < 3*N:
        r = N - rn % N - 1
        c = N - 1
        dir = 3
    else:
        r = 0
        c = N - rn % N - 1
        dir = 2

    ball_root = [(r, c)]
    for _ in range(N - 1):
        r = r + d4[dir][0]
        c = c + d4[dir][1]
        ball_root.append((r, c))

    for br, bc in ball_root:
        for team in teams:
            for i, player in enumerate(team.players):
                if br == player.r and bc == player.c:
                    team.score += (i+1) ** 2
                    reverse_team_player(team)
                    reverse_team_root(team)
                    return


def print_teams():
    for team in teams:
        print(f"Team{team.id}")
        for player in team.players:
            print(player)
        print()


d4 = [(-1, 0), (0, 1), (1, 0), (0, -1)]

N, M, K = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]
teams = [Team(i) for i in range(M)]

t_idx = 0
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            new_player = Player(i, j)
            new_player.is_head = True
            create_team_players(teams[t_idx], new_player)
            create_team_root(teams[t_idx])
            t_idx += 1


for i in range(K):
    for team in teams:
        move_team_players(team)
    roll_ball(i)

total = 0
for team in teams:
    total += team.score

print(total)
