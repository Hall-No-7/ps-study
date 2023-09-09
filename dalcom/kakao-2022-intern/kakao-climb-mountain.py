import heapq


def dijkstra(graph, gates, summits, n):
    pq = []

    dist = [float("inf") for _ in range(n + 1)]
    for gate in gates:
        dist[gate] = 0
        heapq.heappush(pq, (0, gate))

    while len(pq):
        d_val, v = heapq.heappop(pq)

        if v in summits or d_val > dist[v]:
            continue

        for u, val in graph[v]:
            if dist[u] > max(d_val, val):
                dist[u] = max(d_val, val)
                heapq.heappush(pq, (dist[u], u))

    result = [float("inf"), float("inf")]
    for summit in summits:
        print(summit, dist[summit])
        if dist[summit] < result[1]:
            result = [summit, dist[summit]]

    return result


def solution(n, paths, gates, summits):
    answer = [float("inf"), float("inf")]

    graph = [[] for _ in range(n + 1)]

    for path in paths:
        i, j, w = path
        graph[i].append((j, w))
        graph[j].append((i, w))

    summits.sort()
    summits = set(summits)

    answer = dijkstra(graph, gates, summits, n)

    return answer


solution(4, [[1, 3, 1], [1, 4, 1], [4, 2, 1]], [1], [2, 3, 4])
