#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define INF 987654321

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 987654321;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) arr[i][i] = 0;
    for (int i = 0; i < fares.size(); i++) {
        arr[fares[i][0]][fares[i][1]] = fares[i][2];
        arr[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][k] == INF || arr[k][j] == INF) continue;
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (arr[s][i] == INF || arr[i][a] == INF || arr[i][b] == INF) continue;
        answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);
    }

    return answer;
}
int main() {
    int n = 6;  // 노드 개수
    int s = 4;  // 출발 노드
    int a = 6;  // A 도착 노드
    int b = 2;  // B 도착 노드
    std::vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    cout << solution(n, s, a, b, fares) << endl;
}