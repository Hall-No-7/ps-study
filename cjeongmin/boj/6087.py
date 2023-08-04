import sys, heapq

input = lambda: sys.stdin.readline().rstrip()
INF = float("inf")


def dijkstra():
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]
    pq: list[tuple[int, tuple[int, int], int]] = [(0, positions[0], -1)]
    dist = [[INF] * W for _ in range(H)]
    visited = [[[[False] * W for _ in range(H)] for _ in range(4)] for _ in range(4)]

    while len(pq):
        cost, pos, d = heapq.heappop(pq)
        y, x = pos

        if (y, x) == positions[1]:
            return cost

        if dist[y][x] < cost:
            continue
        dist[y][x] = cost

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if not (0 <= nx < W and 0 <= ny < H):
                continue
            if MAP[ny][nx] == "*":
                continue
            if visited[d][i][ny][nx]:
                continue
            nextCost = cost + 1 if d != -1 and d != i else cost
            if dist[ny][nx] >= nextCost:
                dist[ny][nx] = nextCost
                visited[d][i][ny][nx] = True
                heapq.heappush(pq, (nextCost, (ny, nx), i))
    return -1


W, H = map(int, input().split())
MAP = [input() for _ in range(H)]

positions = []
for y in range(H):
    for x in range(W):
        if MAP[y][x] == "C":
            positions.append((y, x))
print(dijkstra())
