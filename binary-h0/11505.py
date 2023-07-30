import sys, math
sys.setrecursionlimit(10 ** 9)

input = lambda: sys.stdin.readline().rstrip()

def update(seg, s, e, node, idx, val):
    if (idx < s) or (idx > e):
        return
    if s == e:
        seg[node] = val
        return
    mid = (s + e) // 2
    update(seg, s, mid, node * 2, idx, val)
    update(seg, mid + 1, e, node * 2 + 1, idx, val)
    seg[node] = seg[node * 2] * seg[node * 2 + 1] % 1000000007


def get(seg, s, e, node, l, r):
    if (l > e) or (r < s):
        return 1
    if (l <= s) and (e <= r):
        return seg[node]
    mid = (s + e) // 2
    return get(seg, s, mid, node * 2, l, r) * get(seg, mid + 1, e, node * 2 + 1, l, r) % 1000000007

def initSegTree(arr, seg, node, start, end):
    if start == end:
        seg[node] = arr[start]
        return seg[node]
    mid = (start + end) // 2
    seg[node] = (initSegTree(arr, seg, node * 2, start, mid) * initSegTree(arr, seg, node * 2 + 1, mid + 1, end)) % 1000000007
    return seg[node]

def main():
    N, M, K = map(int, input().split())
    arr = [int(input()) for _ in range(N)]
    seg = [0] * (1 << (int(math.ceil(math.log2(N))) + 1))
    initSegTree(arr, seg, 1, 0, N - 1)
    for _ in range(M + K):
        a, b, c = map(int, input().split())
        if a == 1:
            update(seg, 0, N - 1, 1, b - 1, c)
        else:
            print(get(seg, 1, N - 1, 1, b - 1, c - 1))
    
main()