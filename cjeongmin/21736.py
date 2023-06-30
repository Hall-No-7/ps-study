from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

N, M = map(int, input().split())
campus = [input() for _ in range(N)]

curr = (-1, -1)
for r in range(N):
    for c in range(M):
        if campus[r][c] == "I":
            curr = (r, c)

ans = 0
visited = [[False for _ in range(M)] for _ in range(N)]
visited[curr[0]][curr[1]] = True
q: deque[tuple[int, int]] = deque()
q.append(curr)
while len(q):
    y, x = q.popleft()
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if not (0 <= nx < M and 0 <= ny < N):
            continue
        if visited[ny][nx] or campus[ny][nx] == "X":
            continue
        if campus[ny][nx] == "P":
            ans += 1

        visited[ny][nx] = True
        q.append((ny, nx))
print(ans if ans != 0 else "TT")
