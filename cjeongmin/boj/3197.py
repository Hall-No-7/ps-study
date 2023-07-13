from sys import stdin
from collections import deque

input = lambda: stdin.readline().rstrip()


def find(parent: list[int], x: int) -> int:
    if parent[x] == x:
        return x
    alt = find(parent, parent[x])
    parent[x] = alt
    return alt


def union(parent: list[int], u: int, v: int) -> bool:
    u = find(parent, u)
    v = find(parent, v)
    if u == v:
        return False
    if u < v:
        u, v = v, u
    parent[u] = v
    return True


def findSwansAndWater(
    parent: list[int], lake: list[list[str]]
) -> tuple[list[tuple[int, int]], set[tuple[int, int]]]:
    swans = []
    water = set()
    for r in range(R):
        for c in range(C):
            if lake[r][c] == "X":
                continue
            if lake[r][c] == "L":
                swans.append((r, c))

            for i in range(4):
                x, y = c + dx[i], r + dy[i]
                if not (0 <= x < C and 0 <= y < R):
                    continue
                if lake[y][x] == "X":
                    water.add((r, c))
                    continue
                union(parent, r * C + c, y * C + x)
    return list(set(swans)), water


dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
R, C = map(int, input().split())
lake = [list(input()) for _ in range(R)]
parent = [i for i in range(R * C + 1)]
swans, water = findSwansAndWater(parent, lake)

ans = 0
queue = deque(water)
while find(parent, swans[0][0] * C + swans[0][1]) != find(
    parent, swans[1][0] * C + swans[1][1]
):
    ans += 1

    for _ in range(len(queue)):
        r, c = queue.popleft()
        for i in range(4):
            x, y = c + dx[i], r + dy[i]
            if not (0 <= x < C and 0 <= y < R):
                continue

            if lake[y][x] != "X":
                continue

            lake[y][x] = "."
            queue.append((y, x))
            union(parent, r * C + c, y * C + x)

            for j in range(4):
                nx, ny = x + dx[j], y + dy[j]
                if not (0 <= nx < C and 0 <= ny < R):
                    continue
                if lake[ny][nx] == "X":
                    continue
                union(parent, y * C + x, ny * C + nx)

print(ans)
