// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

struct Node {
    int row, col, cnt, vertical;
    Node(int row, int col, int cnt, int vertical)
        : row(row), col(col), cnt(cnt), vertical(vertical) {}
};

int dx[4] = {0, 0, -1, 1}; // row
int dy[4] = {-1, 1, 0, 0}; // col

int rotateX[2][4] = {{-1, -1, 0, 0}, {0, 1, 0, 1}}; // rotateX[1] vertical
int rotateY[2][4] = {{0, 1, 0, 1}, {-1, -1, 0, 0}}; // rotateY[1] vertical

bool visited[2][100][100] = {
    {
        {false},
    },
};

int answer = INT32_MAX, goal;

bool CheckingMove(vector<vector<int>> &board, int row, int col, int vertical) {
    if (vertical == 1) { // 수직
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

void BFS(vector<vector<int>> &board, Node &node) {
    queue<Node> q;
    q.push(node);
    visited[node.vertical][node.row][node.col] = true;
    while (!q.empty()) {
        Node tmp = q.front();
        q.pop();

        if (tmp.vertical == 1) { // 수직
            if (tmp.row == goal - 1 && tmp.col == goal) {
                answer = min(answer, tmp.cnt);
                return;
            }
        } else { // 수평
            if (tmp.row == goal && tmp.col == goal - 1) {
                answer = min(answer, tmp.cnt);
                return;
            }
        }

        for (int i = 0; i < 4; i++) { // 이동
            int newRow = tmp.row + dx[i], newCol = tmp.col + dy[i],
                newVertical = tmp.vertical;
            if (CheckingMove(board, newRow, newCol, newVertical)) {
                if (!visited[newVertical][newRow][newCol]) {
                    visited[newVertical][newRow][newCol] = true;
                    q.push(Node(newRow, newCol, tmp.cnt + 1, newVertical));
                }
            }
        }

        for (int i = 0; i < 4; i++) { // 회전
            if (i < 2 && tmp.vertical != 1)
                continue;
            else if (i >= 2 && tmp.vertical == 1)
                continue;

            int newRow = tmp.row + dx[i];
            int newCol = tmp.col + dy[i];
            int newVertical = tmp.vertical;

            if (CheckingMove(board, newRow, newCol, newVertical)) {
                // 해당 방향으로 이동했을 때 통과하지못하면 회전도 못함
                int idx;
                if (newVertical == 1) // i가 0, 1
                    idx = 2 * i;
                else
                    idx = 2 * i - 4; // i가 2, 3
                for (int j = idx; j < ((idx == 0) ? 1 : idx) * 2; j++) {
                    if (!visited[(newVertical == 1) ? 0 : 1]
                                [tmp.row + rotateX[newVertical][j]]
                                [tmp.col +
                                 rotateY[newVertical][j]]) { // 해당 방향으로
                        // 방문했는지 확인
                        q.push(Node(tmp.row + rotateX[newVertical][j],
                                    tmp.col + rotateY[newVertical][j],
                                    tmp.cnt + 1, (newVertical == 1) ? 0 : 1));
                        visited[(newVertical == 1) ? 0 : 1]
                               [tmp.row + rotateX[newVertical][j]]
                               [tmp.col + rotateY[newVertical][j]] = true;
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
    goal = board.size() - 1;
    Node node = Node(0, 0, 0, 0);
    BFS(board, node);
    cout << answer << endl;
}