// By Hongs
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define INF INT32_MAX
using namespace std;

int N;
int costs[3][201];

void Dijkstra(int type, int start, vector<vector<pair<int, int>>> &edges) {
    for (int i = 1; i <= N; i++)
        costs[type][i] = INF;
    costs[type][start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});
    while (!pq.empty()) {
        int node = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();

        if (cost > costs[type][node])
            continue;

        for (int i = 0; i < edges[node].size(); i++) {
            int next_node = edges[node][i].first;
            int next_cost = edges[node][i].second + cost;

            if (next_cost < costs[type][next_node]) {
                costs[type][next_node] = next_cost;
                pq.push({next_node, -next_cost});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    N = n;
    vector<vector<pair<int, int>>> edges(n + 1);
    for (auto &v : fares) {
        edges[v[0]].push_back({v[1], v[2]});
        edges[v[1]].push_back({v[0], v[2]});
    }

    Dijkstra(0, s, edges); // 출발지점으로 부터 모든 정점의 최단거리
    Dijkstra(1, a, edges); // a의 도착지점으로 부터 모든 정점의 최단거리
    Dijkstra(2, b, edges); // b의 도착지점으로 부터 모든 정점의 최단거리

    for (int i = 1; i <= n; i++)
        answer = min(answer, costs[0][i] + costs[1][i] + costs[2][i]);
    return answer;
}