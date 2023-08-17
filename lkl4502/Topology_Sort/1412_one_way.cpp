// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int main() {
    fast_io;
    int n;
    cin >> n;
    vector<string> edges(n);
    for (int i = 0; i < n; i++)
        cin >> edges[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (edges[i][j] == 'Y' && edges[j][i] == 'Y') { // 양방향 제거
                edges[i][j] = 'N';
                edges[j][i] = 'N';
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (edges[i][k] == 'Y' && edges[k][j] == 'Y')
                    edges[i][j] = 'Y';
            }
        }
    }

    string answer = "YES";
    for (int i = 0; i < n; i++)
        if (edges[i][i] == 'Y') {
            answer = "NO";
            break;
        }
    cout << answer << endl;
}