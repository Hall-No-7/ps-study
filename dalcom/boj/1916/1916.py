from sys import stdin as input
import heapq

input = open("/Volumes/Program/ps-study/dalcom/boj/1916/input.txt", "rt")

INF = 1 << 30
N = int(input.readline())
M = int(input.readline())

graph = [[] for _ in range(N + 1)]
dist = [INF for _ in range(N + 1)]

for _ in range(M):
    u, v, w = map(int, input.readline().split())
    graph[u].append((v, w))

start, end = map(int, input.readline().split())


def dijk(start):
    pq = []
    heapq.heapify(pq)
    dist[start] = 0
    heapq.heappush(pq, (0, start))

    while pq:
        cost, p = heapq.heappop(pq)

        if cost > dist[p]:
            continue

        for v, w in graph[p]:
            new_cost = cost + w
            if new_cost < dist[v]:
                dist[v] = new_cost
                heapq.heappush(pq, (new_cost, v))


dijk(start)
print(dist[end])
