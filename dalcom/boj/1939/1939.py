from sys import stdin as input
from collections import deque

input = open("/Volumes/Program/ps-study/dalcom/1939/input.txt", "rt")

n, m = map(int, input.readline().split())
graph = []
parent = [i for i in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, input.readline().split())
    graph.append((a, b, c))

graph.sort(key=lambda x: -x[2])

start, end = map(int, input.readline().split())


def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]


def union(a, b):
    a = find(a)
    b = find(b)

    if a != b:
        parent[a] = b


for a, b, c in graph:
    union(a, b)

    if find(start) == find(end):
        print(c)
        break
