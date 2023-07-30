#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;
typedef long long ll;
#define MAX_SIZE 1000000

ll arr[MAX_SIZE], tree[MAX_SIZE * 4];

ll Init(int idx, int start, int end) {
    if (start == end)
        return tree[idx] = arr[start];
    int mid = (start + end) / 2;
    return tree[idx] =
               Init(idx * 2, start, mid) + Init(idx * 2 + 1, mid + 1, end);
}

ll Update(int idx, int start, int end, int changeIdx, ll value) {
    if (changeIdx < start || changeIdx > end)
        return tree[idx];
    if (start == end)
        return tree[idx] = value;
    int mid = (start + end) / 2;
    return tree[idx] = Update(idx * 2, start, mid, changeIdx, value) +
                       Update(idx * 2 + 1, mid + 1, end, changeIdx, value);
}

ll Query(int idx, int start, int end, int left, int right) {
    if (start > right || end < left)
        return 0;
    if (start >= left && end <= right)
        return tree[idx];
    int mid = (start + end) / 2;
    return Query(idx * 2, start, mid, left, right) +
           Query(idx * 2 + 1, mid + 1, end, left, right);
}

int main() {
    fast_io;
    int numCnt, updateCnt, sumCnt;
    cin >> numCnt >> updateCnt >> sumCnt;
    memset(arr, 0, numCnt * sizeof(ll));
    memset(tree, 0, 4 * numCnt * sizeof(ll));

    for (int i = 0; i < numCnt; i++)
        cin >> arr[i];
    Init(1, 0, numCnt - 1);
    ll a, b, c;
    for (int i = 0; i < updateCnt + sumCnt; i++) {
        cin >> a >> b >> c;
        if (a == 1)
            Update(1, 0, numCnt - 1, b - 1, c);
        else
            cout << Query(1, 0, numCnt - 1, b - 1, c - 1) << endl;
    }
}