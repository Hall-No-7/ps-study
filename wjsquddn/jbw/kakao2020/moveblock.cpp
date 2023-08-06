#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
int N;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visit[101][101][4];

bool safe(int y, int x) { return y >= 0 && x >= 0 && y < N && x < N; }
int solution(vector<vector<int>> board) {
    N = board.size();

    queue<tuple<int, int, int, int>> q;

    q.push({0, 0, 0, 1});
    visit[0][0][1] = 1;

    q.push({0, 0, 1, 3});
    visit[0][1][3] = 1;

    while (!q.empty()) {
        auto [cnt, y1, x1, dir] = q.front();
        q.pop();

        int y2 = y1 + dy[dir];
        int x2 = x1 + dx[dir];

        if ((y1 == N - 1 && x1 == N - 1) || (y2 == N - 1 && x2 == N - 1)) {
            return cnt;
        }

        for (int d = 0; d < 4; ++d) {
            int ny1 = y1 + dy[d];
            int nx1 = x1 + dx[d];
            int ny2 = y2 + dy[d];
            int nx2 = x2 + dx[d];

            if (!safe(ny1, nx1) || !safe(ny2, nx2)) continue;
            if (board[ny1][nx1] || board[ny2][nx2]) continue;

            if (!visit[ny1][nx1][dir]) {
                visit[ny1][nx1][dir] = 1;
                q.push({cnt + 1, ny1, nx1, dir});
            }
            if (!visit[ny2][nx2][(dir + 2) % 4]) {
                visit[ny2][nx2][(dir + 2) % 4] = 1;
                q.push({cnt + 1, ny2, nx2, (dir + 2) % 4});
            }

            if ((dir + 1) % 2 == d % 2) {
                if (!visit[y1][x1][d]) {
                    visit[y1][x1][d] = 1;
                    q.push({cnt + 1, y1, x1, d});
                }
                if (!visit[y2][x2][(dir + 2) % 4]) {
                    visit[y2][x2][(dir + 2) % 4] = 1;
                    q.push({cnt + 1, y2, x2, (dir + 2) % 4});
                }
            }
        }
    }

    return 0;
}