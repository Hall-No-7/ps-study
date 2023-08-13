from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/boj/2458/input.txt", "rt")

n, m = map(int, input.readline().split())

income = [[] for _ in range(n + 1)]
outcome = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input.readline().split())
    income[b].append(a)
    outcome[a].append(b)


cnt = 0


def dfs(visited, node, graph):
    global cnt
    if len(graph[node]) == 0:
        return

    for i in graph[node]:
        if visited[i]:
            continue
        visited[i] = True
        cnt += 1
        dfs(visited, i, graph)


answer = 0
for i in range(1, n + 1):
    visited = [False for _ in range(n + 1)]
    visited[i] = True
    cnt = 0
    dfs(visited, i, income)
    income_cnt = cnt
    cnt = 0
    dfs(visited, i, outcome)
    outcome_cnt = cnt
    if income_cnt + outcome_cnt == n - 1:
        answer += 1

print(answer)
