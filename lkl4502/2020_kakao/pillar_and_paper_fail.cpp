// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

struct BoardInfo {
    bool pillar = false, paper = false;
};

BoardInfo board[101][101];

int N;

bool InstallItem(int row, int col, bool type) {
    if (type) { // 보인 경우
        if (board[row][col].pillar)
            return true;
        if (board[row][col + 1].pillar)
            return true;
        if (col > 0 && board[row][col - 1].paper && board[row][col + 1].paper)
            return true;
        return false;
    } else {          // 기둥
        if (row == 0) // 바닥인 경우 설치가능
            return true;
        if (row > 0 && (board[row - 1][col].pillar || // 다른 기둥 위에 있던가
                        board[row - 1][col].paper)) // 밑에 보가 있는 경우
            return true;
        if (row > 0 && col > 0 &&
            board[row - 1][col - 1].paper) // 밑에 보가 있는 경우
            return true;
        return false;
    }
}

bool CheckingDelete(bool type) { // 기둥 설치 가능 여부
    // 삭제인 경우
    // 해당 좌표를 false로 바꾸고 주변 설치 가능여부 확인
    for (int i = 0; i < N + 1; i++)
        for (int j = 0; j < N + 1; j++) { // 삭제시에는 둘다 고려
            if (board[i][j].pillar && !InstallItem(i, j, type))
                return false;
            if (board[i][j].paper && !InstallItem(i, j, type))
                return false;
        }
    return true;
}

int main() {
    fast_io;
    // (x, y) -> 좌표, a : 기둥인지 보인지? 0이면 기둥 1이면 보
    // b 행동을 결정 0이면 삭제 1이면 설치
    N = 5;
    vector<vector<int>> build_frame = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1},
                                       {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1},
                                       {4, 2, 1, 1}, {3, 2, 1, 1}};

    int cnt = 0;
    for (auto &it : build_frame) {
        int row = it[1], col = it[0];
        bool type = it[2] == 1 ? true : false; // true면 보, false면 기둥
        bool install = it[3] == 1 ? true : false; // true면 설치, false 면 삭제
        if (type && row > 0)
            row--;
        cout << row << " " << col << endl;
        if (install) {
            if (InstallItem(row, col, type)) {
                cnt++;
                if (type)
                    board[row][col].paper = true;
                else
                    board[row][col].pillar = true;
            }
        } else {
            if (type)
                board[row][col].paper = false;
            else
                board[row][col].pillar = false;
            if (!CheckingDelete(type)) {
                if (type)
                    board[row][col].paper = true;
                else
                    board[row][col].pillar = true;
            } else
                cnt--;
        }
    }
    vector<vector<int>> answer(cnt, vector<int>(3));
    int idx = 0;
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            if (board[j][i].pillar) {
                answer[idx][0] = i, answer[idx][1] = j, answer[idx][2] = 0;
                idx++;
            }
            if (board[j][i].paper) {
                answer[idx][0] = i, answer[idx][1] = j + 1, answer[idx][2] = 1;
                idx++;
            }
        }
    }

    sort(answer.begin(), answer.end(), [](vector<int> &v1, vector<int> &v2) {
        if (v1[0] == v2[0]) {
            if (v1[1] == v2[1])
                return v1[2] < v2[2];
            else
                return v1[1] < v2[1];
        } else
            return v1[0] < v2[0];
    });
}