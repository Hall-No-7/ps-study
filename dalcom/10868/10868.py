from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/10868/input.txt", "rt")

n, m = map(int, input.readline().split())

arr = []

for _ in range(n):
    arr.append(int(input.readline()))

min_tree = [0 for _ in range(len(arr) * 4 + 1)]


def mininit(start, end, index):
    if start == end:
        min_tree[index] = arr[start]
        return arr[start]

    mid = (start + end) // 2

    min_tree[index] = min(
        mininit(start, mid, index * 2), mininit(mid + 1, end, index * 2 + 1)
    )
    return min_tree[index]


def minsearch(start, end, index, left, right):
    if left > end or right < start:
        return 1000000000

    if left <= start and right >= end:
        return min_tree[index]

    mid = (start + end) // 2
    min_val = min(
        minsearch(start, mid, index * 2, left, right),
        minsearch(mid + 1, end, index * 2 + 1, left, right),
    )

    return min_val


mininit(0, len(arr) - 1, 1)

for _ in range(m):
    a, b = map(int, input.readline().split())
    print(
        minsearch(0, len(arr) - 1, 1, a - 1, b - 1),
    )
