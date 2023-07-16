import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

def find(root, x):
    if root[x] != x:
        root[x] = find(root, root[x])
    return root[x]

def union(root, x, y):
    x = find(root, x)
    y = find(root, y)
    if x < y:
        root[y] = x
    else:
        root[x] = y

def bfs(graph, x):
    que = deque()
    que.append((x, 0))
    visited = set([x])
    max_depth = 0
    while que:
        x, depth = que.pop()
        if max_depth < depth:
            max_depth = depth
        for nx in graph[x]:
            if nx in visited:
                continue
            visited.add(nx)
            que.append((nx, depth + 1))
    return max_depth


def main():
    N = int(input())
    M = int(input())
    root = [i for i in range(N+1)]
    count = [0 for _ in range(N+1)]
    graph = [[] for _ in range(N + 1)]
    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
        count[a] += 1
        count[b] += 1
        union(root, a, b)
    for i in range(1, N + 1):
        find(root, i)

    depths = [bfs(graph, i) for i in range(0, N+1)]
    groups = dict()
    print(len(sorted(list(set(root)))[1:]))
    for i in range(1, N + 1):
        if root[i] in groups:
            _, depth = groups[root[i]]
            if depth > depths[i]:
                groups[root[i]] = (i, depths[i])
        else:
            groups[root[i]] = (i, depths[i])
    ans = []
    for p, g in groups.values():
        ans.append(p)
    for i in sorted(ans):
        print(i)
main()

