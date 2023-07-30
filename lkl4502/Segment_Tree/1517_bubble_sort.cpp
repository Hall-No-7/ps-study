#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;
#define MAX_SIZE 500000

/*배열을 입력받았을 때
본인의 뒤로 본인보다 작은 수가 몇개가 있는지?
    --> 이것이 해당 숫자를 정렬 할때 발생하는 swap의 횟수*/

pair<int, int> arr[MAX_SIZE];
int tree[4 * MAX_SIZE];

int Query(int idx, int start, int end, int left, int right) {
    if (end < left || start > right)
        return 0;
    if (start >= left && end <= right)
        return tree[idx];
    int mid = (start + end) / 2;
    return Query(idx * 2, start, mid, left, right) +
           Query(idx * 2 + 1, mid + 1, end, left, right);
}

int Update(int idx, int start, int end, int changeIdx, int value) {
    if (changeIdx < start || changeIdx > end)
        return tree[idx];
    if (start == end)
        return tree[idx] = value;
    int mid = (start + end) / 2;
    return tree[idx] = Update(idx * 2, start, mid, changeIdx, value) +
                       Update(idx * 2 + 1, mid + 1, end, changeIdx, value);
}

int main() {
    fast_io;
    int n, num;
    cin >> n;
    memset(arr, 0, n * sizeof(pair<int, int>)); // arr 초기화
    memset(tree, 0, 4 * n * sizeof(int));
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[i] = {num, i};
    }
    sort(arr, arr + n);

    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += Query(1, 0, n - 1, arr[i].second, n - 1);
        Update(1, 0, n - 1, arr[i].second, 1);
    }

    cout << answer << endl;
}