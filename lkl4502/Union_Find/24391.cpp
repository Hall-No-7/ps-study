#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;
#define MAX_LECTURE 100001

int arr[MAX_LECTURE];

void init(int n) {
    memset(arr, -1, (n + 1) * sizeof(int));
    arr[0] = 0;
}

int find(int num) {
    if (arr[num] < 0)
        return num;
    arr[num] = find(arr[num]);
    return arr[num];
}

void merge(int num1, int num2) {
    int rootNum1 = find(num1), rootNum2 = find(num2);
    if (rootNum1 == rootNum2)
        return;
    if (arr[rootNum1] <= arr[rootNum2]) {
        arr[rootNum1] += arr[rootNum2];
        arr[rootNum2] = rootNum1;
    } else {
        arr[rootNum2] += arr[rootNum1];
        arr[rootNum1] = rootNum2;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, u, v;
    cin >> N >> M;
    init(N);
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        merge(u, v);
    }

    int lectureCode, idx, count = 0;
    cin >> lectureCode;
    idx = find(lectureCode);
    for (int i = 1; i < N; i++) {
        cin >> lectureCode;
        int tmp = find(lectureCode);
        if (idx != tmp) {
            idx = tmp;
            count++;
        }
    }
    cout << count << ENDL;
}