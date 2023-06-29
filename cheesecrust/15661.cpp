#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int map[21][21];
int visited[21];
int ans = 2147000000;

int cal() {
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = i; j <= n; j++) {
            if (visited[i] && visited[j]) {
                sum1 = sum1 + map[i][j] + map[j][i];
            } else if (!visited[i] && !visited[j]) {
                sum2 = sum2 + map[i][j] + map[j][i];
            }
        }
    }

    return abs(sum1 - sum2);
}

void combination(int cnt) {
    if (cnt == n) {
        ans = min(ans, cal());
        return;
    }

    visited[cnt] = true;
    combination(cnt + 1);
    visited[cnt] = false;
    combination(cnt + 1);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    combination(1);

    cout << ans << '\n';
    return 0;
}
