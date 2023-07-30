import sys
import math

input = lambda: sys.stdin.readline().rstrip()


def init(a, tree, node, start, end):
    if start == end:
        tree[node] = a[start]
        return

    init(a, tree, node * 2, start, (start + end) // 2)
    init(a, tree, node * 2 + 1, (start + end) // 2 + 1, end)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


def update(a, tree, node, start, end, index, val):
    if index < start or end < index:
        return
    if start == end:
        a[index] = val
        tree[node] = val
        return

    update(a, tree, node * 2, start, (start + end) // 2, index, val)
    update(a, tree, node * 2 + 1, (start + end) // 2 + 1, end, index, val)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


def update_lazy(tree, lazy, node, start, end):
    if lazy[node] != 0:
        tree[node] += lazy[node] * (end - start + 1)
        if start != end:
            lazy[node * 2] += lazy[node]
            lazy[node * 2 + 1] += lazy[node]
        lazy[node] = 0


def update_range(tree, lazy, node, start, end, left, right, diff):
    update_lazy(tree, lazy, node, start, end)
    if end < left or right < start:
        return
    if left <= start and end <= right:
        tree[node] += (end - start + 1) * diff
        if start != end:
            lazy[node * 2] += diff
            lazy[node * 2 + 1] += diff
        return

    update_range(tree, lazy, node * 2, start, (start + end) // 2, left, right, diff)
    update_range(
        tree, lazy, node * 2 + 1, (start + end) // 2 + 1, end, left, right, diff
    )
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


def query(tree, lazy, node, start, end, left, right):
    update_lazy(tree, lazy, node, start, end)
    if end < left or right < start:
        return 0
    if left <= start and end <= right:
        return tree[node]

    lsum = query(tree, lazy, node * 2, start, (start + end) // 2, left, right)
    rsum = query(tree, lazy, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return lsum + rsum


N = int(input())
arr = list(map(int, input().split()))

h = math.ceil(math.log2(N))
size = 1 << (h + 1)
tree = [0] * size
lazy = [0] * size

init(arr, tree, 1, 0, N - 1)
for _ in range(int(input())):
    q, *args = list(map(int, input().split()))
    if q == 1:
        i, j, k = args
        update_range(tree, lazy, 1, 0, N - 1, i - 1, j - 1, k)
    else:
        x = args[0]
        print(query(tree, lazy, 1, 0, N - 1, x - 1, x - 1))
