import sys
from collections import deque

input = sys.stdin.readline

def main():
    N, M = map(int, input().rstrip().split())
    graph = [list(map(int, input().rstrip().split())) for _ in range(N)]
    H, W, Sr, Sc, Fr, Fc = map(int, input().rstrip().split())
    Sr, Sc, Fr, Fc = Sr - 1, Sc - 1, Fr - 1, Fc - 1
    dr, dc = [0, 0, 1, -1], [1, -1, 0, 0]
    visited = [[False for _ in range(M)]  for __ in range(N)]
    visited[Sr][Sc] = True
    que = deque()
    que.append((Sr, Sc, 0))

    def scan(r, c):
        for i in range(H):
            if graph[r + i][c] == 1 or graph[r + i][c + W - 1] == 1:
                return False
        for j in range(W):
            if not ((graph[r][c + j] == 0) and (graph[r + H - 1][c + j] == 0)):
                return False
        return True

    def bfs():
        while que:
            r, c, cnt = que.popleft()
            # print(r, c, cnt)
            if r == Fr and c == Fc:
                return cnt
            for i in range(4):
                nr, nc = r + dr[i], c + dc[i]
                if not (0 <= nr and 0 <= nc and nr + H - 1 < N and nc + W - 1 < M):
                    continue
                if visited[nr][nc]:
                    continue
                if graph[nr][nc] == 0:
                    visited[nr][nc] = True
                    if scan(nr, nc):
                        que.append((nr, nc, cnt + 1))
        return -1
    
    print(bfs())
main()