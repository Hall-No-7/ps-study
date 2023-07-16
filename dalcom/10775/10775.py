from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/10775/input.txt", "rt")

g = int(input.readline())
parent = [i for i in range(g + 1)]


def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]


result = 0
for i in range(int(input.readline())):
    a = int(input.readline())
    gn = find(a)

    if gn == 0:
        break

    parent[gn] = parent[gn - 1]
    result += 1

print(result)
