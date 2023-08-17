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
    int totalCase;
    cin >> totalCase;
    while (totalCase--) {
        int n, k;
        cin >> n >> k;
        vector<int> inDegree(n + 1, 0);
        vector<int> times(n + 1);
        vector<vector<int>> edges(n + 1);
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> times[i];
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
            inDegree[b]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                dp[i] = times[i];
            }
        }

        for (int i = 1; i <= n; i++) {
            if (q.empty()) {
                cout << "break" << endl;
                break;
            }
            int cur = q.front();
            q.pop();
            for (int j = 0; j < edges[cur].size(); j++) {
                int next = edges[cur][j];
                dp[next] = max(dp[next], dp[cur] + times[next]);
                if (--inDegree[next] == 0)
                    q.push(next);
            }
        }

        int last;
        cin >> last;
        cout << dp[last] << endl;
    }
}