#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;
#define MAX_SIZE 100000

int arr[MAX_SIZE];
long long tree[MAX_SIZE * 4];

long long Init(int idx, int start, int end) {
    if (start == end)
        return tree[idx] = arr[start];
    int mid = (start + end) / 2;
    return tree[idx] =
               Init(idx * 2, start, mid) + Init(idx * 2 + 1, mid + 1, end);
}

long long Update(int idx, int start, int end, int changeIdx, long long value) {
    if (changeIdx < start || changeIdx > end)
        return tree[idx];
    if (start == end)
        return tree[idx] = value;
    int mid = (start + end) / 2;
    return tree[idx] = Update(idx * 2, start, mid, changeIdx, value) +
                       Update(idx * 2 + 1, mid + 1, end, changeIdx, value);
}

long long Query(int idx, int start, int end, int left, int right) {
    if (end < left || start > right)
        return 0;
    if (start >= left && end <= right)
        return tree[idx];
    int mid = (start + end) / 2;
    return Query(idx * 2, start, mid, left, right) +
           Query(idx * 2 + 1, mid + 1, end, left, right);
}

int main() {
    fast_io;
    int n, q;
    cin >> n >> q;
    memset(arr, 0, n * sizeof(int));
    memset(tree, 0, 4 * n * sizeof(long long));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Init(1, 0, n - 1);
    int x, y, a, b;
    while (q--) { // x, y, a와 같이 인덱스를 담는 것은 -1을 해주어야한ㄷ.
        cin >> x >> y >> a >> b;
        a--, x--, y--;
        if (x > y)
            swap(x, y);
        cout << Query(1, 0, n - 1, x, y) << endl;
        Update(1, 0, n - 1, a, b);
    }
}