#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define MAX_NEURON 100001

int arr[MAX_NEURON];
int answer = 0;

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
    if (rootNum1 == rootNum2) {
        answer++; // union하기 전에도 rootNum이 같으면 사이클이 생기기때문에,
                  // 끊는 횟수 ++
        return;
    }
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

    int *rootNum = find_if(arr, arr + N + 1, [](int &num) { return num < 0; });
    int *tmp =
        find_if(rootNum + 1, arr + N + 1, [](int &num) { return num < 0; });
    while (tmp < arr + N + 1) {
        answer++; // rootNum들을 연결하는 것이므로 answer++
        tmp = find_if(tmp + 1, arr + N + 1, [](int &num) { return num < 0; });
    }
    cout << answer << endl;
}