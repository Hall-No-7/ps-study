#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321
#define ARR_SIZE 101
int n;
int arr[ARR_SIZE][ARR_SIZE];

void floyd_warshall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (arr[j][i] != INF && arr[i][k] != INF) {
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
                }
            }
        }
    }
}

int main() {
    int m;
    cin >> n >> m;
    // 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (arr[a][b] > c) arr[a][b] = c;
    }
    floyd_warshall();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || arr[i][j] == INF)
                cout << 0 << " ";
            else {
                cout << arr[i][j] << " ";
            }
        }

        cout << endl;
    }
}