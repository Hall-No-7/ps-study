import sys, heapq

input = lambda: sys.stdin.readline().rstrip()
INF = float("INF")


def dijkstra(start):
    ret = [0] * (N + 1)

    pq = [(0, start, [start])]
    dist = [INF] * (N + 1)

    while len(pq):
        cost, curr, path = heapq.heappop(pq)

        if dist[curr] < cost:
            continue

        for nxt, w1 in graph[curr]:
            w2 = cost + w1
            nextPath = path + [nxt]
            if dist[nxt] >= w2:
                dist[nxt] = w2
                ret[nxt] = nextPath[1]
                heapq.heappush(pq, (w2, nxt, nextPath))

    ret[start] = 0
    return ret


N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))

table = []
for s in range(1, N + 1):
    table.append(dijkstra(s))

for row in table:
    for v in row[1:]:
        print(v if v != 0 else "-", end=" ")
    print()
