from sys import stdin as input
import heapq

input = open("/Volumes/Program/ps-study/dalcom/boj/1753/input.txt", "rt")

INF = 1 << 30
V, E = map(int, input.readline().split())
start = int(input.readline())

graph = [[] for _ in range(V + 1)]

for _ in range(E):
    u, v, w = map(int, input.readline().split())
    graph[u].append((v, w))

dist = [INF for _ in range(V + 1)]


def dijkstra(start):
    pq = []
    heapq.heappush(pq, (0, start))
    dist[start] = 0

    while pq:
        cost, p = heapq.heappop(pq)

        if cost > dist[p]:
            continue

        for v, w in graph[p]:  # v: 정점, w: 코스트
            new_cost = cost + w
            if new_cost < dist[v]:
                dist[v] = new_cost
                heapq.heappush(pq, (new_cost, v))


dijkstra(start)

for i in dist[1:]:
    if i >= INF:
        print("INF")
    else:
        print(i)
