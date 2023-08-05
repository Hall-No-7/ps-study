#include <bits/stdc++.h>
using namespace std;
#define DIV 1000000007

vector<int> arr(1000001);
vector<long> tree(1000001, 1);

long init(int start, int end, int index) {
    if (start == end) {
        return tree[index] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[index] = (init(start, mid, index * 2) % DIV) *
                         (init(mid + 1, end, index * 2 + 1) % DIV);
}

long mul(int start, int end, int index, int left, int right) {
    if (left > end || right < start) {
        return 1;
    }

    if (left <= start && end <= right) {
        return tree[index];
    }

    int mid = (start + end) / 2;
    return (mul(start, mid, index * 2, left, right) % DIV) *
           (mul(mid + 1, end, index * 2 + 1, left, right) % DIV);
}

long long update(int start, int end, int treeIdx, int arrIdx, long long val) {
    if (arrIdx < start || arrIdx > end) {
        return tree[treeIdx];
    }

    if (start == end) {
        return tree[treeIdx] = val;
    }

    int mid = (start + end) / 2;
    tree[treeIdx] = (update(start, mid, treeIdx * 2, arrIdx, val) % DIV) *
                    (update(mid + 1, end, treeIdx * 2 + 1, arrIdx, val) % DIV);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init(0, n - 1, 1);

    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b = b - 1;

        if (a == 1) {
            arr[b] = c;
            update(0, n - 1, 1, b, c);
        } else if (a == 2) {
            c = c - 1;
            cout << mul(0, n - 1, 1, b, c) % DIV << '\n';
        }
    }

    long long a = 6, b = 4;
    cout << b / a;

    return 0;
}