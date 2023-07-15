#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

#define MAX_LEN 1000000

class DisjointSet {
  public:
    int arr[MAX_LEN];
    DisjointSet(int n) {
        for (int i = 0; i <= n; i++)
            arr[i] = -1;
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
        if (arr[rootNum1] <
            arr[rootNum2]) { // 음수이므로 작은 것이 size가 더 큰 것이다.
            arr[rootNum1] += arr[rootNum2];
            arr[rootNum2] = rootNum1;
        } else {
            arr[rootNum2] += arr[rootNum1];
            arr[rootNum1] = rootNum2;
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, type, a, b;
    cin >> n >> m;
    DisjointSet disjointSet(n);
    for (int i = 0; i < m; i++) {
        cin >> type >> a >> b;
        if (type == 0)
            disjointSet.merge(a, b);
        else {
            int x = disjointSet.find(a);
            int y = disjointSet.find(b);
            if (x == y)
                cout << "yes" << ENDL;
            else
                cout << "no" << ENDL;
        }
    }
}