// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int dx[4] = {0, 0, -1, 1}; // row
int dy[4] = {-1, 1, 0, 0}; // col

int rotateX[2][4] = {{0, 1, 0, 1}, {-1, -1, 0, 0}}; // rotateX[0] vertical
int rotateY[2][4] = {{-1, -1, 0, 0}, {0, 1, 0, 1}}; // rotateY[0] vertical

int answer = INT32_MAX, goal;

bool visited[2][100][100] = {
    {
        {false},
    },
};

bool CheckingMove(vector<vector<int>> &board, int row, int col, bool vertical) {
    if (vertical) { // 수직
        if (row < 0 || col < 0 || row > goal || col > goal || row + 1 > goal ||
            board[row][col] != 0 || board[row + 1][col] != 0)
            return false;
    } else { // 가로
        if (row < 0 || col < 0 || row > goal || col > goal || col + 1 > goal ||
            board[row][col] != 0 || board[row][col + 1] != 0)
            return false;
    }
    return true;
}

void BackTracking(vector<vector<int>> &board, pair<int, int> &drone, int cnt,
                  bool vertical) {
    if (vertical) { // 수직
        if (drone.first == goal - 1 && drone.second == goal) {
            answer = min(answer, cnt);
            return;
        }
    } else { // 수평
        if (drone.first == goal && drone.second == goal - 1) {
            answer = min(answer, cnt);
            return;
        }
    }
    int type = (vertical) ? 1 : 0;
    for (int i = 0; i < 4; i++) {
        int newRow = drone.first + dx[i];
        int newCol = drone.second + dy[i];
        if (CheckingMove(board, newRow, newCol, vertical)) {
            if (!visited[type][newRow][newCol]) {
                visited[type][newRow][newCol] = true;
                drone.first += dx[i], drone.second += dy[i];
                BackTracking(board, drone, cnt + 1, vertical);
                visited[type][newRow][newCol] = false;
                drone.first -= dx[i], drone.second -= dy[i];
            }
        }
    }

    for (int i = 0; i < 4; i++) { // 회전식에 인덱스 조정을 어떤 식으로 해야하고
                                  // 검사는 어떤 식으로 해야하는지 고민할 것
        if (i < 2 && !vertical)
            continue;
        else if (i > 2 && vertical)
            continue;

        int newRow = drone.first + dx[i];
        int newCol = drone.second + dy[i];

        if (vertical) {
            if (CheckingMove(board, newRow, newCol, vertical)) {
                for (int j = 2 * i; j < 2 * (i + 1); j++) {
                    if (!visited[type][drone.first + rotateX[0][j]]
                                [drone.second + rotateY[0][j]]) {
                        drone.first += rotateX[0][j],
                            drone.second += rotateY[0][j];
                        visited[type][drone.first][drone.second] = true;
                        BackTracking(board, drone, cnt + 1, !vertical);
                        visited[type][drone.first][drone.second] = false;
                        drone.first -= rotateX[0][j],
                            drone.second -= rotateY[0][j];
                    }
                }
            }
        } else {
            if (CheckingMove(board, newRow, newCol, vertical)) {
                for (int j = 2 * (i - 2); j < 2 * (i - 1); j++) {
                    if (!visited[type][drone.first + rotateX[1][j]]
                                [drone.second + rotateY[1][j]]) {
                        drone.first += rotateX[1][j],
                            drone.second += rotateY[1][j];
                        visited[type][drone.first][drone.second] = true;
                        BackTracking(board, drone, cnt + 1, !vertical);
                        visited[type][drone.first][drone.second] = false;
                        drone.first -= rotateX[1][j],
                            drone.second -= rotateY[1][j];
                    }
                }
            }
        }
    }
}

int main() {
    fast_io;
    vector<vector<int>> board = {{0, 0, 0, 1, 1},
                                 {0, 0, 0, 1, 0},
                                 {0, 1, 0, 1, 1},
                                 {1, 1, 0, 0, 1},
                                 {0, 0, 0, 0, 0}};
    pair<int, int> drone = {0, 0};
    goal = board.size() - 1;
    visited[0][0][0] = true;
    BackTracking(board, drone, 0, false);
    cout << answer << endl;
}