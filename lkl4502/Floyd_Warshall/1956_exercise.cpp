// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
#define INF 4000400
using namespace std;

int main() {
    fast_io;
    int v, e;
    cin >> v >> e;
    vector<vector<int>> dist(v + 1, vector<int>(v + 1, INF));
    int a, b, c;
    while (e--) {
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int result = INF;
    for (int i = 1; i <= v; i++)
        result = min(result, dist[i][i]);

    if (result == INF)
        result = -1;
    cout << result << endl;
}