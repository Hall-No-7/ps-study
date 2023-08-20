from sys import stdin as input
from collections import deque

input = open("/Volumes/Program/ps-study/dalcom/boj/1516/input.txt", "rt")

n = int(input.readline())

graph = [[] for _ in range(n + 1)]
indegree = [0 for _ in range(n + 1)]
req_times = [0 for _ in range(n + 1)]
answer = [0 for _ in range(n + 1)]

for i in range(1, n + 1):
    time, *arr = list(map(int, input.readline().split()))
    req_times[i] = time
    for j in arr[:-1]:
        graph[j].append(i)
        indegree[i] += 1

queue = deque()

for i in range(1, n + 1):
    if indegree[i] == 0:
        queue.append((i, req_times[i]))

while len(queue):
    v, time = queue.popleft()

    answer[v] += req_times[v]

    for u in graph[v]:
        indegree[u] -= 1
        answer[u] = max(answer[u], answer[v])

        if indegree[u] == 0:
            queue.append((u, answer[u]))

print("\n".join(map(str, answer[1:])))
