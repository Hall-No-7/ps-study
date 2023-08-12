import heapq


def dijkstra(graph, n, start):
    INF = float("INF")
    
    pq = [(0, start)]
    dist = [INF] * (n + 1)
    while pq:
        w, curr = heapq.heappop(pq)
        
        if dist[curr] < w:
            continue
        dist[curr] = w    
        
        for nxt, v in graph[curr]:
            if v + w < dist[nxt]:
                dist[nxt] = v + w
                heapq.heappush(pq, (v + w, nxt))
    
    return dist


def solution(n, s, a, b, fares):
    answer = 0
    
    graph = [[] for _ in range(n + 1)]
    for u, v, w in fares:
        graph[u].append((v, w))
        graph[v].append((u, w))
    
    dist_s = dijkstra(graph, n, s)
    dist_a = dijkstra(graph, n, a)
    dist_b = dijkstra(graph, n, b)
    
    dist = dist_s[:]
    for i in range(1, n + 1):
        dist[i] += dist_a[i] + dist_b[i]
    
    return min(dist)
