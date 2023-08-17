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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    vector<int> inDegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        inDegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    for (int i = 1; i <= n; i++) {
        if (q.empty())
            break;
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for (int j = 0; j < edges[cur].size(); j++) {
            int next = edges[cur][j];
            if (--inDegree[next] == 0)
                q.push(next);
        }
    }
    cout << endl;
}