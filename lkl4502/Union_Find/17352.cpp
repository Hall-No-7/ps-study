#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;
#define MAX_ISLAND 300001

int arr[MAX_ISLAND];

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

    int N, a, b;
    cin >> N;
    init(N);

    while (cin >> a >> b)
        merge(a, b);

    int *start = find_if(arr, arr + N + 1, [](int &num) { return num < 0; });
    int *end =
        find_if(start + 1, arr + N + 1, [](int &num) { return num < 0; });
    cout << start - arr << " " << end - arr << ENDL;
}