#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;
#define MAX_N 100000

int tree[4 * MAX_N], arr[MAX_N];

int Compare(int x, int y) {
    if (arr[x] == arr[y])
        return (x < y) ? x : y;
    return (arr[x] < arr[y]) ? x : y;
}

int Init(int idx, int start, int end) { // start와 end는 기존 배열의 범위
    if (start == end)
        return tree[idx] = start; // idx 저장

    int mid = (start + end) / 2;
    return tree[idx] = Compare(Init(2 * idx, start, mid),
                               Init(2 * idx + 1, mid + 1, end));
}

int Update(int idx, int start, int end, int changeIdx) {
    if (changeIdx < start || changeIdx > end || start == end)
        return tree[idx];
    int mid = (start + end) / 2;
    return tree[idx] = Compare(Update(2 * idx, start, mid, changeIdx),
                               Update(2 * idx + 1, mid + 1, end, changeIdx));
}

int main() {
    fast_io;
    int n, type, queryCnt;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(tree, 0, 4 * n * sizeof(int));
    Init(1, 0, n - 1);

    cin >> queryCnt;
    while (queryCnt--) {
        cin >> type;
        if (type == 1) {
            int changeIdx, value;
            cin >> changeIdx >> value;
            arr[--changeIdx] = value;
            Update(1, 0, n - 1, changeIdx);
            continue;
        }
        cout << tree[1] + 1 << endl;
    }
}