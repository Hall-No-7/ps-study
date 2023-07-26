#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int N;

bool findBlock(vector<vector<int>> &board, int row, int col) {
    int num = board[row][col];
    if (num == 0)
        return false;

    if (row + 2 < N) { // 3층 높이 블럭
        if (num == board[row + 1][col] &&
            num == board[row + 2][col]) { // 3층인거 확인
            if (col + 1 < N && (num == board[row][col + 1] ||
                                num == board[row + 1][col + 1])) {
                for (int i = row; i < N; i++)
                    board[i][col] = board[i][col + 1] = 0;
                return false;
            } else if (col + 1 < N && num == board[row + 2][col + 1] &&
                       board[row][col + 1] == 0 &&
                       board[row + 1][col + 1] == 0) {
                board[row][col] = board[row + 1][col] = board[row + 2][col] =
                    board[row + 2][col + 1] = 0;
                return true;
            } else if (col - 1 >= 0 && (num == board[row][col - 1] ||
                                        num == board[row + 1][col - 1])) {
                for (int i = row; i < N; i++)
                    board[i][col] = board[i][col - 1] = 0;
                return false;
            } else if (col - 1 >= 0 && num == board[row + 2][col - 1] &&
                       board[row][col - 1] == 0 &&
                       board[row + 1][col - 1] == 0) {
                board[row][col] = board[row + 1][col] = board[row + 2][col] =
                    board[row + 2][col - 1] = 0;
                return true;
            }
        }
    }

    // 이쪽으로 넘어오는 것은 다 2층 높이 블럭
    if (col + 2 < N) {
        if (row + 1 < N) {
            if (num == board[row][col + 1] && num == board[row][col + 2]) {
                for (int i = row; i < N; i++)
                    board[i][col] = board[i][col + 1] = board[i][col + 2] = 0;
                return false;
            }

            if (num == board[row + 1][col + 1] &&
                num == board[row + 1][col + 2] && board[row][col + 1] == 0 &&
                board[row][col + 2] == 0) {
                board[row][col] = board[row + 1][col] =
                    board[row + 1][col + 1] = board[row + 1][col + 2] = 0;
                return true;
            }
        }
    }

    if (col - 2 >= 0) {
        if (row + 1 < N) {
            if (num == board[row + 1][col - 1] &&
                num == board[row + 1][col - 2] && board[row][col - 1] == 0 &&
                board[row][col - 2] == 0) {
                board[row][col] = board[row + 1][col] =
                    board[row + 1][col - 1] = board[row + 1][col - 2] = 0;
                return true;
            }
        }
    }
    if (col - 1 >= 0 && col + 1 < N) {
        if (row + 1 < N) {
            if (num == board[row + 1][col - 1] &&
                num == board[row + 1][col + 1] && board[row][col - 1] == 0 &&
                board[row][col + 1] == 0) {
                board[row][col] = board[row + 1][col] =
                    board[row + 1][col - 1] = board[row + 1][col + 1] = 0;
                return true;
            }
        }
    }
    return false;
}

int main() {
    fast_io;
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 0, 0, 0}, {0, 0, 0, 0, 0, 4, 4, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 4, 0, 0, 0}, {0, 0, 0, 2, 3, 0, 0, 0, 5, 5},
        {1, 2, 2, 2, 3, 3, 0, 0, 0, 5}, {1, 1, 1, 0, 0, 0, 0, 0, 0, 5}};
    for (auto &row : board) {
        for (auto &element : row)
            cout << element << " ";
        cout << endl;
    }

    N = board.size();
    int answer = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (findBlock(board, row, col)) {
                cout << row << " " << col << endl;
                col = -1;
                answer++;
            }
        }
    }
    cout << endl;
    for (auto &row : board) {
        for (auto &element : row)
            cout << element << " ";
        cout << endl;
    }
    cout << endl;

    cout << answer << endl;
}