import sys

INF = float("INF")
input = lambda: sys.stdin.readline().rstrip()


def floyd_warshall(graph):
    for t in range(1, N + 1):
        for s in range(1, N + 1):
            for e in range(1, N + 1):
                graph[s][e] = min(graph[s][e], graph[s][t] + graph[t][e])


N, M = map(int, input().split())
graph = [[INF] * (N + 1) for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a][b] = 1

floyd_warshall(graph)

ans = 0
for s in range(1, N + 1):
    cnt = 0
    for e in range(1, N + 1):
        if graph[s][e] != INF or graph[e][s] != INF:
            cnt += 1

    if cnt == N - 1:
        ans += 1
print(ans)
