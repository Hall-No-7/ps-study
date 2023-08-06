// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;
#define INF INT32_MAX

int n, m, t, s, g, h;

void Dijkstra(int start, vector<int> &dist,
              vector<vector<pair<int, int>>> &edges) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int node = q.front(), distance = dist[node];
        q.pop();
        for (int i = 0; i < edges[node].size(); i++) {
            int nextNode = edges[node][i].first;
            int nextDistance = edges[node][i].second + distance;

            if (nextDistance < dist[nextNode]) {
                dist[nextNode] = nextDistance;
                q.push(nextNode);
            }
        }
    }
}

int main() {
    fast_io;
    int totalCount;
    cin >> totalCount;
    while (totalCount--) {
        vector<vector<pair<int, int>>> edges;
        int crossDist;
        cin >> n >> m >> t; // 교차로, 도로, 목적지 후보
        cin >> s >> g >> h; // 시작 노드, 교차하는 두 노드

        edges.resize(n + 1);
        int a, b, d;
        for (int i = 0; i < m; i++) { // 간선 저장
            cin >> a >> b >> d;
            edges[a].push_back({b, d});
            edges[b].push_back({a, d});
            if ((a == g && b == h) || (a == h && b == g))
                crossDist = d;
        }

        vector<int> basicDist(n + 1, INF), gDist(n + 1, INF);
        Dijkstra(s, basicDist, edges); // 시작부터 다른 노드에 대한 최단 거리

        if (basicDist[g] < basicDist[h]) // g가 더 먼쪽
            swap(g, h);
        Dijkstra(g, gDist, edges);

        vector<int> answer;
        for (int i = 0; i < t; i++) {
            cin >> a;
            if (basicDist[a] == basicDist[h] + crossDist + gDist[a])
                answer.push_back(a);
        }
        sort(answer.begin(), answer.end());

        for (auto &it : answer)
            cout << it << " ";
        cout << endl;
    }
}