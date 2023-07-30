from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/11505/input.txt", "rt")

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
    tree[index] = (
        init(start, mid, index * 2) * init(mid + 1, end, index * 2 + 1) % 1000000007
    )
    return tree[index]


def mul(start, end, index, left, right):
    if left > end or right < start:
        return 1

    if left <= start and right >= end:
        return tree[index]

    mid = (start + end) // 2
    return (
        mul(start, mid, index * 2, left, right)
        * mul(mid + 1, end, index * 2 + 1, left, right)
        % 1000000007
    )


def update(start, end, index, arr_index, diff):
    if arr_index < start or arr_index > end:
        return

    if start == end:
        tree[index] = diff
        return

    mid = (start + end) // 2
    update(start, mid, index * 2, arr_index, diff)
    update(mid + 1, end, index * 2 + 1, arr_index, diff)
    tree[index] = tree[index * 2] * tree[index * 2 + 1] % 1000000007


init(0, len(arr) - 1, 1)

for _ in range(m + k):
    a, b, c = map(int, input.readline().split())
    b = b - 1
    if a == 1:
        arr[b] = c
        update(0, len(arr) - 1, 1, b, c)
    elif a == 2:
        c = c - 1
        print(int(mul(0, len(arr) - 1, 1, b, c)) % 1000000007)
