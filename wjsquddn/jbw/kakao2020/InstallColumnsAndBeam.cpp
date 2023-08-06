#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 보드에는 끝 부분의 종류가 들어간다.
vector<vector<int>> board;
vector<vector<int>> answer;
int N;
void init(int n) {
    n++;
    vector<int> v(n, -1);
    for (int i = 0; i <= n; i++) {
        board.push_back(v);
    }
}
// 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나,
//  다른 기둥 위에 있어야 합니다.
//  보는 한쪽 끝 부분이 기둥 위에 있거나,
// 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
bool checkinsert(int x, int y, int a) {
    // 기등
    if (a == 0) {
        if (y == 0 || (x != 0 && board[y][x - 1] == 1) || (y != 0 && board[y - 1][x] == 0) || (board[y][x] == 1)) {
            return true;
        } else {
            return false;
        }
    }
    // 보
    else {
        if ((y != 0 && board[y - 1][x] == 0) || (x != N && y != 0 && board[y - 1][x + 1] == 0) || ((x != 0 && board[y][x - 1] == 1) && (x != N && board[y][x + 1] == 1))) {
            return true;
        } else {
            return false;
        }
    }
}
bool checkdelete(int x, int y, int a) {
    // 기둥
    board[y][x] = -1;
    for (int y = 0; y <= N; y++) {
        for (int x = 0; x <= N; x++) {
            if (board[y][x] == -1) {
                continue;
            } else {
                if (board[y][x] == 0) {
                    if (!checkinsert(x, y, 0)) {
                        return false;
                    }
                } else {
                    if (!checkinsert(x, y, 0)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
void insert(vector<int> insertion) {
    int x = insertion[0];
    int y = insertion[1];
    // a 0 : 기둥 1: 보
    int a = insertion[2];
    // b 0 :  삭제 1: 설치
    int b = insertion[3];
    vector<int> cnt;
    // 삽입이 가능한지 확인하기
    if (b == 1) {
        if (checkinsert(x, y, a)) {
            if (a == 0) {
                board[y][x] = 0;
            } else {
                board[y][x] = 1;
            }
        } else {
            return;
        }
    } else {
        int type = board[y][x];
        if (!checkdelete(x, y, a)) {
            board[y][x] = type;
            return;
        }
    }
    // 가능하다면 삽입
    // 불가능 하다면 return
    //  삭제 가능한지 확인하기
    // 가능하다면 삭제
    // 불가능 하다면 return
}

void printboard() {
    for (int y = N; y >= 0; y--) {
        for (int x = 0; x <= N; x++) {
            if (board[y][x] == -1) {
                cout << board[y][x];
            } else {
                cout << " " << board[y][x];
            }
        }
        cout << endl;
    }
    cout << endl;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N = n;
    // 보드 초기화
    init(n);
    // 보드에 삽입
    for (int i = 0; i < build_frame.size(); i++) {
        insert(build_frame[i]);
        // printboard();
    }
    // answer에 넣어주기

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (board[y][x] == -1) {
                continue;
            } else {
                vector<int> cnt;
                if (board[y][x] == 0) {
                    cnt.push_back(x);
                    cnt.push_back(y);
                    cnt.push_back(0);
                } else {
                    cnt.push_back(x);
                    cnt.push_back(y);
                    cnt.push_back(1);
                }
                answer.push_back(cnt);
            }
        }
    }
    return answer;
}
void print(int n, vector<vector<int>> build_frame) {
    // printboard();
    vector<vector<int>> answer = solution(n, build_frame);
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << answer[i][j] << ",";
        }
        cout << endl;
    }
}
int main() {
    int n;
    vector<vector<int>> build_frame;
    // build_frame = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}};
    // n = 5;
    // print(n, build_frame);
    n = 5;
    build_frame = {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}};
    print(n, build_frame);
}