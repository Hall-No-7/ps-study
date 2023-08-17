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
    vector<vector<int>> edges(n + 1);
    vector<int> inDegree(n + 1, 0);
    vector<int> times(n + 1);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int time, cnt, workNum;
        cin >> time >> cnt;
        times[i] = time;
        for (int j = 0; j < cnt; j++) {
            cin >> workNum;
            edges[workNum].push_back(i);
            inDegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (inDegree[i] == 0) {
            q.push(i);
            dp[i] = times[i];
        }

    for (int i = 1; i <= n; i++) {
        if (q.empty())
            break;
        int x = q.front();
        q.pop();
        for (int j = 0; j < edges[x].size(); j++) {
            int next = edges[x][j];
            dp[next] = max(dp[next], dp[x] + times[next]);
            if (--inDegree[next] == 0)
                q.push(next);
        }
    }
    sort(dp.begin(), dp.end());
    cout << dp.back() << endl;
}