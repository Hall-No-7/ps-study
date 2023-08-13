from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/boj/1956/input.txt", "rt")

v, e = map(int, input.readline().split())

dist = [[float("INF") for _ in range(v + 1)] for _ in range(v + 1)]

for _ in range(e):
    a, b, c = map(int, input.readline().split())
    dist[a][b] = c

for i in range(1, v + 1):
    dist[i][i] = 0

for k in range(1, v + 1):
    for i in range(1, v + 1):
        for j in range(1, v + 1):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])


answer = float("INF")
for i in range(1, v + 1):
    for j in range(i + 1, v + 1):
        if dist[i][j] < float("INF") and dist[j][i] < float("INF"):
            answer = min(answer, dist[i][j] + dist[j][i])

print(answer if answer < float("INF") else -1)
