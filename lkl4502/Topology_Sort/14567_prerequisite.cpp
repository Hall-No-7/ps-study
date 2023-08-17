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
    vector<int> inDegree(n + 1, 0), answer(n, 1);
    vector<vector<int>> edges(n + 1);
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
        if (q.empty()) // 정렬 불가능
            break;
        int x = q.front();
        q.pop();
        for (int j = 0; j < edges[x].size(); j++) {
            answer[edges[x][j] - 1] = answer[x - 1] + 1;
            if (--inDegree[edges[x][j]] == 0)
                q.push(edges[x][j]);
        }
    }
    for (auto it : answer)
        cout << it << " ";
    cout << endl;
}