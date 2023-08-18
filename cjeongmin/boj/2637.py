import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

N = int(input())
M = int(input())

in_degree = [0] * (N + 1)
graph = [[] for _ in range(N + 1)]
reverse = [[] for _ in range(N + 1)]
for _ in range(M):
    X, Y, K = map(int, input().split())
    graph[Y].append((X, K))  # Y는 X를 만드는데 K개 사용된다.
    in_degree[X] += 1

q = deque()
for i in range(1, N + 1):
    if in_degree[i] == 0:
        q.append(i)
default_part = set(q)

dp = [[0] * (N + 1) for _ in range(N + 1)]
while q:
    curr = q.popleft()

    for nxt, cnt in graph[curr]:
        if curr in default_part:
            dp[nxt][curr] += cnt
        else:
            for i in range(1, N + 1):
                dp[nxt][i] += cnt * dp[curr][i]

        in_degree[nxt] -= 1
        if in_degree[nxt] == 0:
            q.append(nxt)

for i in range(1, N + 1):
    if dp[N][i]:
        print(i, dp[N][i])
