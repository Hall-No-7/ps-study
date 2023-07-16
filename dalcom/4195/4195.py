from sys import stdin as input
from collections import defaultdict

input = open("/Volumes/Program/ps-study/dalcom/4195/input.txt", "rt")

t = int(input.readline())


def find(x, parent):
    if parent[x][0] == x:
        return x
    tmp_size = parent[x][1]
    parent[x] = (find(parent[x][0], parent), tmp_size)
    return parent[x][0]


def union(a, b, parent):
    a = find(a, parent)
    b = find(b, parent)

    if a != b:
        if parent[a][1] < parent[b][1]:
            a, b = b, a

        parent[a] = (a, parent[a][1] + parent[b][1])
        parent[b] = (a, 0)

    return max(parent[a][1], parent[b][1])


for _ in range(t):
    f = int(input.readline())
    parent = defaultdict(lambda: ("", 0))
    for _ in range(f):
        a, b = input.readline().split()
        if parent[a][0] == "":
            parent[a] = (a, 1)
        if parent[b][0] == "":
            parent[b] = (b, 1)

        print(union(a, b, parent))
