class Point:
    def __init__(self, r, c):
        self.r = r
        self.c = c

    def __add__(self, other):
        self.r += other.r
        self.c += other.c

    def out_of_bound(self):
        if self.r < 0 or self.r >= N or self.c < 0 or self.c >= N:
            return True
        return False


class Roo:
    def __init__(self, p):
        self.p = p
        self.dir = 0


class Santa:
    def __init__(self, p, idx):
        self.p = p
        self.id = idx
        self.live = True
        self.stun = 0
        self.score = 0

    def __str__(self):
        return f"산타{self.id} ({self.p.r}, {self.p.c})"


def calc_distance(p1: Point, p2: Point):
    return (p1.r - p2.r) ** 2 + (p1.c - p2.c) ** 2


def update_roo_pos_and_dir(roo: Roo, dir):
    roo.p.r += d8[dir][0]
    roo.p.c += d8[dir][1]
    roo.dir = dir


def update_santa_pos_and_live(santa: Santa, p: Point):
    santa.p.r += p.r
    santa.p.c += p.c

    if santa.p.r < 0 or santa.p.r >= N or santa.p.c < 0 or santa.p.c >= N:
        santa.live = False


def move_roo(roo: Roo):
    result = [Santa(Point(-100, -100), -1), float('INF')]
    for santa in santas:
        if not santa.live:
            continue
        dis = calc_distance(santa.p, roo.p)
        if result[1] > dis:
            result = [santa, dis]
        elif result[1] == dis:
            if result[0].p.r < santa.p.r:
                result = [santa, dis]
            elif result[0].p.r == santa.p.r and result[0].p.c < santa.p.c:
                result = [santa, dis]

    result2 = [float('INF'), -1]
    for i, d in enumerate(d8):
        pp = Point(roo.p.r + d[0], roo.p.c + d[1])
        dis = calc_distance(result[0].p, pp)
        if result2[0] > dis:
            result2 = [dis, i]

    update_roo_pos_and_dir(roo, result2[1])

    if result[0].p.r == roo.p.r and result[0].p.c == roo.p.c:
        collision(True, result2[1], result[0])


def move_santa(santa: Santa):
    if not santa.live or santa.stun > 0:
        return

    result = [calc_distance(roo.p, santa.p), 8]

    for i in range(6, -1, -2):
        rr, cc = santa.p.r + d8[i][0], santa.p.c + d8[i][1]
        dis = calc_distance(roo.p, Point(rr, cc))
        # 벽이라 못가는 경우
        if rr < 0 or rr >= N or cc < 0 or cc >= N:
            continue
        # 다른 산타가 있어서 못가는 경우
        can_go = True
        for st in santas:
            if not st.live:
                continue
            if st.id == santa.id:
                continue
            if st.p.r == rr and st.p.c == cc:
                can_go = False
                break
        if not can_go:
            continue
        # 갈 수 있는 경우
        if result[0] >= dis:
            result = [dis, i]

    if result[1] == 8:
        return

    update_santa_pos_and_live(santa, Point(d8[result[1]][0], d8[result[1]][1]))

    if santa.p.r == roo.p.r and santa.p.c == roo.p.c:
        r_dir = (result[1] + 4) % 8
        collision(False, r_dir, santa)


def collision(by_roo, dir, santa):
    santa.stun = 2
    if by_roo:
        santa.score += C
        pp = Point(d8[dir][0] * C, d8[dir][1] * C)
        update_santa_pos_and_live(santa, pp)
        if not santa.live:
            return
        interactive(dir, santa)
        return

    santa.score += D
    pp = Point(d8[dir][0] * D, d8[dir][1] * D)
    update_santa_pos_and_live(santa, pp)
    if not santa.live:
        return
    interactive(dir, santa)


def interactive(dir, santa):
    for st in santas:
        if not st.live:
            continue
        if st.id == santa.id:
            continue
        if st.p.r == santa.p.r and st.p.c == santa.p.c:
            update_santa_pos_and_live(st, Point(d8[dir][0], d8[dir][1]))
            if not st.live:
                return
            interactive(dir, st)


def init_stun(santa):
    santa.stun = max(0, santa.stun - 1)


def give_score():
    for santa in santas:
        if santa.live:
            santa.score += 1


def game_over():
    for santa in santas:
        if santa.live:
            return False
    return True


d8 = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

N, M, P, C, D = map(int, input().split())
roo_p = list(map(int, input().split()))
sans_p = [list(map(int, input().split())) for _ in range(P)]

roo = Roo(Point(roo_p[0] - 1, roo_p[1] - 1))
santas = sorted([Santa(Point(x[1] - 1, x[2] - 1), x[0]) for x in sans_p], key=lambda x: x.id)

for _ in range(M):
    move_roo(roo)
    for santa in santas:
        move_santa(santa)
        init_stun(santa)
    give_score()
    if game_over():
        break

for santa in santas:
    print(santa.score, end=' ')
