import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    K, M, P = map(int, input().split())

    in_degree = [0] * (M + 1)
    graph = [[] for _ in range(M + 1)]
    for _ in range(P):
        A, B = map(int, input().split())
        graph[A].append(B)  # A -> B
        in_degree[B] += 1

    q = deque()
    strahler: list[tuple[int, int]] = [(0, 0) for _ in range(M + 1)]

    for i in range(1, M + 1):
        if in_degree[i] == 0:
            q.append(i)
            strahler[i] = (1, 1)

    while q:
        curr = q.popleft()

        for nxt in graph[curr]:
            if strahler[nxt][0] < strahler[curr][0]:
                strahler[nxt] = (strahler[curr][0], 1)
            elif strahler[nxt][0] == strahler[curr][0]:
                strahler[nxt] = (strahler[curr][0], strahler[curr][1] + 1)

            in_degree[nxt] -= 1
            if in_degree[nxt] == 0:
                if strahler[nxt][1] > 1:
                    strahler[nxt] = (strahler[nxt][0] + 1, 1)
                q.append(nxt)

    print(K, strahler[M][0])
