import sys
import math

input = lambda: sys.stdin.readline().rstrip()


def init(a, tree, node, start, end):
    if start == end:
        tree[node] = a[start]
    else:
        init(a, tree, node * 2, start, (start + end) // 2)
        init(a, tree, node * 2 + 1, (start + end) // 2 + 1, end)
        tree[node] = tree[node * 2] * tree[node * 2 + 1]


def query(tree, node, start, end, left, right):
    if left > end or right < start:
        return 1
    if left <= start and end <= right:
        return tree[node]
    return query(tree, node * 2, start, (start + end) // 2, left, right) * query(
        tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right
    )


def update(a, tree, node, start, end, index, val):
    if index < start or index > end:
        return
    if start == end:
        a[index] = val
        tree[node] = val
        return
    update(a, tree, node * 2, start, (start + end) // 2, index, val)
    update(a, tree, node * 2 + 1, (start + end) // 2 + 1, end, index, val)
    tree[node] = tree[node * 2] * tree[node * 2 + 1]


while True:
    try:
        N, K = map(int, input().split())
        X = list(
            map(
                lambda x: 1 if int(x) > 0 else (-1 if int(x) < 0 else 0),
                input().split(),
            )
        )
        tree = [0] * (1 << (math.ceil(math.log2(N)) + 1))
        init(X, tree, 1, 0, N - 1)

        res = ""
        for _ in range(K):
            c, a, b = input().split()
            if c == "C":
                b = 1 if int(b) > 0 else (-1 if int(b) < 0 else 0)
                update(X, tree, 1, 0, N - 1, int(a) - 1, b)
            else:
                value = query(tree, 1, 0, N - 1, int(a) - 1, int(b) - 1)
                res += "-" if value < 0 else ("+" if value > 0 else "0")
        print(res)
    except:
        break
