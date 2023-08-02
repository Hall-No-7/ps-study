#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int rotateX[2][4] = {{0, 1, 0, 1}, {-1, -1, 0, 0}}; // rotateX[0] vertical
int rotateY[2][4] = {{-1, -1, 0, 0}, {0, 1, 0, 1}}; // rotateY[0] 은 vertical

int answer = INT32_MAX, goal;

bool visited[100][100] = {
    {false},
};

bool CheckingMove(vector<vector<int>> &board, int row, int col, bool vertical) {
    if (vertical) { // 수직
        if (row < 0 || col < 0 || row > goal || col > goal || row + 1 > goal ||
            board[row][col] == 1 || board[row + 1][col] == 1)
            return false;
    } else { // 가로
        if (row < 0 || col < 0 || row > goal || col > goal || col + 1 > goal ||
            board[row][col] == 1 || board[row][col + 1] == 1)
            return false;
    }
    return true;
}

bool CheckingRotate(vector<vector<int>> &board, int row, int col,
                    bool vertical) {
    if (row < 0 || col < 0 || row > goal || col > goal || board[row][col] == 1)
        return false;
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

    for (int i = 0; i < 4; i++) {
        int newRow = drone.first + dx[i];
        int newCol = drone.second + dy[i];
        if (CheckingMove(board, newRow, newCol, vertical)) {
            if (!visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                cnt++, drone.first += dx[i], drone.second += dy[i];
                BackTracking(board, drone, cnt, vertical);
                visited[newRow][newCol] = false;
                cnt--, drone.first -= dx[i], drone.second -= dy[i];
            }
        }
    }

    for (int i = 0; i < 4; i++) { // 회전식에 인덱스 조정을 어떤 식으로 해야하고
                                  // 검사는 어떤 식으로 해야하는지 고민할 것
        int newRow, newCol;
        int type = (vertical) ? 0 : 1;

        if (vertical) {
            if (i < 2) {
                if (!CheckingRotate(board, drone.first, drone.second + 1,
                                    vertical) ||
                    !CheckingRotate(board, drone.first + 1, drone.second + 1,
                                    vertical))
                    continue;
            } else {
                if (!CheckingRotate(board, drone.first, drone.second - 1,
                                    vertical) ||
                    !CheckingRotate(board, drone.first + 1, drone.second - 1,
                                    vertical))
                    continue;
            }
            newRow = drone.first + rotateX[0][i];
            newCol = drone.second + rotateY[0][i];
        } else {
            if (i < 2) {
                if (!CheckingRotate(board, drone.first - 1, drone.second,
                                    vertical) ||
                    !CheckingRotate(board, drone.first - 1, drone.second + 1,
                                    vertical))
                    continue;
            } else {
                if (!CheckingRotate(board, drone.first + 1, drone.second,
                                    vertical) ||
                    !CheckingRotate(board, drone.first + 1, drone.second + 1,
                                    vertical))
                    continue;
            }
            newRow = drone.first + rotateX[1][i];
            newCol = drone.second + rotateY[1][i];
        }

        if (!visited[newRow][newCol]) {
            visited[newRow][newCol] = true;
            vertical = (vertical) ? false : true;
            cnt++, drone.first += rotateX[type][i],
                drone.second += rotateY[type][i];
            BackTracking(board, drone, cnt, vertical);
            visited[newRow][newCol] = false;
            vertical = (vertical) ? false : true;
            cnt--, drone.first -= rotateX[type][i],
                drone.second -= rotateY[type][i];
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
    visited[0][0] = true;
    BackTracking(board, drone, 0, 0);
    cout << answer << endl;
}