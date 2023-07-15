#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;
#define MAX_FRIEND 1000000

int arr[MAX_FRIEND];

void init(int n) { memset(arr, -1, n * sizeof(int)); }

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
    if (arr[rootNum1] < arr[rootNum2]) {
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

    int totalCount, n, k, a, b, m;
    cin >> totalCount;
    for (int scenario = 1; scenario <= totalCount; scenario++) {
        cin >> n >> k;
        init(n);
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            merge(a, b);
        }
        cin >> m;
        cout << "Scenario " << to_string(scenario) << ":" << ENDL;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            int x = find(a), y = find(b);
            if (x == y)
                cout << 1 << ENDL;
            else
                cout << 0 << ENDL;
        }
        cout << ENDL;
    }
}