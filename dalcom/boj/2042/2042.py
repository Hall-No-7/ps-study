from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/2042/input.txt", "rt")

n, m, k = map(int, input.readline().split())

arr = []

for _ in range(n):
    arr.append(int(input.readline()))

tree = [0 for _ in range(len(arr) * 4 + 1)]


def init(start, end, index):
    if start == end:
        tree[index] = arr[start]
        return tree[index]

    mid = (start + end) // 2
    tree[index] = init(start, mid, index * 2) + init(mid + 1, end, index * 2 + 1)
    return tree[index]


def sum(start, end, index, left, right):
    if left > end or right < start:
        return 0

    if left <= start and right >= end:
        return tree[index]

    mid = (start + end) // 2
    return sum(start, mid, index * 2, left, right) + sum(
        mid + 1, end, index * 2 + 1, left, right
    )


def update(start, end, index, arr_index, diff):
    if arr_index < start or arr_index > end:
        return

    tree[index] += diff

    if start == end:
        return

    mid = (start + end) // 2
    update(start, mid, index * 2, arr_index, diff)
    update(mid + 1, end, index * 2 + 1, arr_index, diff)


init(0, len(arr) - 1, 1)

for _ in range(m + k):
    a, b, c = map(int, input.readline().split())
    b = b - 1
    if a == 1:
        diff = c - arr[b]
        arr[b] = c
        update(0, len(arr) - 1, 1, b, diff)
    elif a == 2:
        c = c - 1
        print(sum(0, len(arr) - 1, 1, b, c))
