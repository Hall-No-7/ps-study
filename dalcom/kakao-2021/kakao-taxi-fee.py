def solution(n, s, a, b, fares):
    answer = float("INF")

    dist = [[float("INF") for _ in range(n + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        dist[i][i] = 0

    for c, d, f in fares:
        dist[c][d] = f
        dist[d][c] = f

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    for i in range(1, n + 1):
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b])

    return answer
