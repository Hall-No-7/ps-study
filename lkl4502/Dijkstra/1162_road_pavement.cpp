// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
typedef long long ll;
using namespace std;
#define LINF 9223372036854775807

int n, m, k;
ll costs[21][10001];
vector<vector<pair<int, int>>> edges;

void Dijkstra() {
    priority_queue<tuple<ll, int, int>>
        pq; // 0 -> 비용, 1 -> 노드 번호, 2 -> 포장도로 개수
    pq.push({0, 1, 0});
    costs[0][1] = 0;
    while (!pq.empty()) {
        ll cost;
        int node, cnt;
        tie(cost, node, cnt) = pq.top();
        cost = -cost;
        pq.pop();

        if (cost > costs[cnt][node]) // cost가 이미 구한 값보다 크면 패스
            continue;
        for (int i = 0; i < edges[node].size(); i++) {
            int next_node = edges[node][i].first;
            ll next_cost = edges[node][i].second + cost;

            if (next_cost < costs[cnt][next_node]) { // 포장도로 X
                costs[cnt][next_node] = next_cost;
                pq.push({-next_cost, next_node, cnt});
            }

            if (cnt < k && cost < costs[cnt + 1][next_node]) { // 포장도로 O
                costs[cnt + 1][next_node] = cost;
                pq.push({-cost, next_node, cnt + 1});
            }
        }
    }
}

int main() {
    fast_io;
    cin >> n >> m >> k;
    int a, b, c;
    edges.resize(n + 1);
    for (int i = 0; i < m; i++) { // 간선 연결
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    for (int i = 0; i <= k; i++)
        for (int j = 1; j <= n; j++)
            costs[i][j] = LINF;

    Dijkstra();

    ll answer = LINF;
    for (int i = 0; i < k + 1; i++)
        answer = min(answer, costs[i][n]);

    cout << answer << endl;
}