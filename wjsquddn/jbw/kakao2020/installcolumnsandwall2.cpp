#include <algorithm>
#include <vector>
using namespace std;
int board[101][101][2];
int N;
bool checkinstall(int x, int y, int a) {
    if (a == 0) {
        if (y == 0) return true;
        if (x > 0 && board[x - 1][y][1]) return true;
        if (y < N && board[x][y][1]) return true;
        if (y > 0 && board[x][y - 1][0]) return true;
    } else {
        if (y > 0 && board[x][y - 1][0]) return true;
        if (x < N && y > 0 && board[x + 1][y - 1][0]) return true;
        if (x > 0 && x < N && board[x - 1][y][1] && board[x + 1][y][1]) return true;
    }
    return false;
}

bool checkdelete(int x, int y, int a) {
    board[x][y][a] = 0;
    if (a == 0) {
        if (y < N && board[x][y + 1][0] && !checkinstall(x, y + 1, 0)) return false;
        if (y < N && board[x][y + 1][1] && !checkinstall(x, y + 1, 1)) return false;
        if (x > 0 && y < N && board[x - 1][y + 1][1] && !checkinstall(x - 1, y + 1, 1)) return false;
    } else {
        if (board[x][y][0] && !checkinstall(x, y, 0)) return false;
        if (x < N && board[x + 1][y][0] && !checkinstall(x + 1, y, 0)) return false;
        if (x > 0 && board[x - 1][y][1] && !checkinstall(x - 1, y, 1)) return false;
        if (x < N && board[x + 1][y][1] && !checkinstall(x + 1, y, 1)) return false;
    }
    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N = n;
    // 보드 초기화
    vector<vector<int>> answer;
    for (auto frame : build_frame) {
        int x = frame[0];
        int y = frame[1];
        int a = frame[2];
        int b = frame[3];
        if (b == 0) {
            if (!checkdelete(x, y, a)) board[x][y][a] = 1;
        } else {
            if (checkinstall(x, y, a)) board[x][y][a] = 1;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (board[i][j][0]) answer.push_back({i, j, 0});
            if (board[i][j][1]) answer.push_back({i, j, 1});
        }
    }
    return answer;
}