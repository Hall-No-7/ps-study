from sys import stdin as input
from collections import deque

input = open("/Volumes/Program/ps-study/dalcom/boj/2623/input.txt", "rt")

n, m = map(int, input.readline().split())

graph = [[] for _ in range(n + 1)]
indegree = [0 for _ in range(n + 1)]

for _ in range(m):
    arr = list(map(int, input.readline().split()))
    for i in range(1, arr[0]):
        graph[arr[i]].append(arr[i + 1])
        indegree[arr[i + 1]] += 1

queue = deque()

for i in range(1, n + 1):
    if indegree[i] == 0:
        queue.append(i)

answer = ""

while len(queue):
    v = queue.popleft()
    answer += str(v)

    for u in graph[v]:
        indegree[u] -= 1
        if indegree[u] == 0:
            queue.append(u)

if len(answer) == n:
    print("\n".join(answer))
else:
    print("0")
