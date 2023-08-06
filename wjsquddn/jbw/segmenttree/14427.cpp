#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<long long> tree;
vector<int> v;
int min_index(int x, int y) {
    if (v[x] == v[y]) {
        return min(x, y);
    }
    return v[x] < v[y] ? x : y;
}
long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = start;
    }
    return tree[node] = min_index(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}
long long update(int node, int start, int end, int idx) {
    if (start > idx || end < idx || start == end) {
        return tree[node];
    }
    return tree[node] = min_index(update(node * 2, start, (start + end) / 2, idx), update(node * 2 + 1, (start + end) / 2 + 1, end, idx));
}
int main() {
    int n, m;
    cin >> n;
    int size = (1 << (int)ceil(log2(n)) + 1);
    tree.resize(size);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    init(1, 0, n - 1);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            int a, b;
            scanf("%d%d", &a, &b);
            v[a - 1] = b;
            update(1, 0, n - 1, a - 1);
        } else {
            printf("%lld\n", tree[1] + 1);
        }
    }
}