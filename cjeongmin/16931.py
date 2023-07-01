N, M = map(int, input().split())
cube = [list(map(int, input().split())) for _ in range(N)]

res = 0
for x in range(M):
    res += cube[0][x]
    for y in range(1, N):
        res += max(cube[y][x] - cube[y - 1][x], 0)

for y in range(N):
    res += cube[y][M - 1]
    for x in range(M - 2, -1, -1):
        res += max(cube[y][x] - cube[y][x + 1], 0)

for x in range(M):
    res += cube[N - 1][x]
    for y in range(N - 2, -1, -1):
        res += max(cube[y][x] - cube[y + 1][x], 0)

for y in range(N):
    res += cube[y][0]
    for x in range(1, M):
        res += max(cube[y][x] - cube[y][x - 1], 0)

print(res + (N * M * 2))
