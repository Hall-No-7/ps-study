import sys

INF = float("INF")
input = lambda: sys.stdin.readline().rstrip()


def floyd_warshall(graph):
    for t in range(1, V + 1):
        for s in range(1, V + 1):
            for e in range(1, V + 1):
                graph[s][e] = min(graph[s][e], graph[s][t] + graph[t][e])


V, E = map(int, input().split())

graph = [[INF] * (V + 1) for _ in range(V + 1)]

for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a][b] = c

floyd_warshall(graph)

ans = INF
for s in range(1, V + 1):
    for e in range(1, V + 1):
        ans = min(ans, graph[s][e] + graph[e][s])
print(ans if ans != INF else -1)
