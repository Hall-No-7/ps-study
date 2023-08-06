#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
#define MAX 20010
#define INF 987654321
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v, e;
    cin >> v >> e;
    int dist[MAX];
    vector<pair<int, int>> Vertex[MAX];
    int k;
    cin >> k;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Vertex[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= v; i++) dist[i] = INF;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, k));
    dist[k] = 0;
    while (pq.empty() == 0) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < Vertex[cur].size(); i++) {
            int next = Vertex[cur][i].first;
            int ncost = Vertex[cur][i].second;
            if (dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else {
            cout << dist[i] << endl;
        }
    }
    return 0;
}