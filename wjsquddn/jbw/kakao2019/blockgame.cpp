#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<vector<int>> Board;
bool canFill(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (Board[i][col] != 0) return false;
    }
    return true;
}
bool check(int row, int col, int h, int w) {
    int empty = 0;
    int lastValue = -1;
    for (int r = row; r < row + h; r++) {
        for (int c = col; c < col + w; c++) {
            if (Board[r][c] == 0) {
                if (!canFill(r, c)) return false;
                if (++empty > 2) return false;
            } else {
                if (lastValue != -1 && lastValue != Board[r][c]) return false;
                lastValue = Board[r][c];
            }
        }
    }
    for (int r = row; r < row + h; r++) {
        for (int c = col; c < col + w; c++) {
            Board[r][c] = 0;
        }
    }
    return true;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    Board = board;
    int cnt;
    do {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= n - 2 && j <= n - 3 && check(i, j, 2, 3)) {
                    cnt++;
                } else if (i <= n - 3 && j <= n - 2 && check(i, j, 3, 2)) {
                    cnt++;
                }
            }
        }
        answer += cnt;
    } while (cnt);

    return answer;
}

int main() {
    vector<vector<int>> board = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 4, 4, 0, 0, 0}, {0, 0, 0, 0, 3, 0, 4, 0, 0, 0}, {0, 0, 0, 2, 3, 0, 0, 0, 5, 5}, {1, 2, 2, 2, 3, 3, 0, 0, 0, 5}, {1, 1, 1, 0, 0, 0, 0, 0, 0, 5}};
    cout << solution(board);
}