#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

/*진짜 개빡치는 문제다 진짜 진짜 진짜 진짜 너무 열받는다 아아아아아아아아
개 빡 쳐
개 오 래 걸 렸 다
밤 샜 다*/

struct Block {
    int maxCol = -1, minCol = 50, maxRow = -1, minRow = 50;
};

int main() {
    fast_io;
    int answer = 0;
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 0, 0, 0}, {0, 0, 0, 0, 0, 4, 4, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 4, 0, 0, 0}, {0, 0, 0, 2, 3, 0, 0, 0, 5, 5},
        {1, 2, 2, 2, 3, 3, 0, 0, 0, 5}, {1, 1, 1, 0, 0, 0, 0, 0, 0, 5}};

    map<int, Block> blockMap;
    int N = board.size();
    int blockCnt = 0;
    for (auto &row : board)
        for (auto &ele : row)
            if (blockCnt < ele)
                blockCnt = ele;

    for (int i = 0; i < blockCnt; i++)
        blockMap[i] = Block();

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            int num = board[row][col]; // 블럭 범위 구하기
            blockMap[num].maxRow = max(blockMap[num].maxRow, row);
            blockMap[num].minRow = min(blockMap[num].minRow, row);
            blockMap[num].maxCol = max(blockMap[num].maxCol, col);
            blockMap[num].minCol = min(blockMap[num].minCol, col);
        }
    }

    vector<int> roof(N, 0);
    for (int col = 0; col < N; col++) {
        for (int row = 0; row < N; row++) {
            if (board[row][col] == 0) // col에 0이 있는 만큼 내리기
                roof[col]++;
            else
                break;
        }
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            int num = board[row][col];
            if (num == 0 || blockMap.find(num) == blockMap.end())
                continue;
            bool flag = false;

            for (int i = blockMap[num].minRow; i < blockMap[num].maxRow + 1;
                 i++) {
                for (int j = blockMap[num].minCol; j < blockMap[num].maxCol + 1;
                     j++) {
                    if (board[i][j] == num)
                        continue;
                    if (board[i][j] == 0 && roof[j] > i)
                        continue;
                    // 밑으로오면 블럭 범위를 다 못채우고 내려오는것 따라서 블럭
                    // 못없앰.
                    flag = true;
                    break;
                }
                if (flag) // 해당 블록의 반복을 끝낸다.
                    break;
            }
            if (flag) // true면 블럭을 없애지못하니까 다음 반복
                continue;
            answer++;
            cout << num << endl;

            for (int i = blockMap[num].minRow; i < blockMap[num].maxRow + 1;
                 i++)
                for (int j = blockMap[num].minCol; j < blockMap[num].maxCol + 1;
                     j++)
                    board[i][j] = 0; // 블록 없애기

            blockMap.erase(num);
            // roof도 내리기
            for (int col = 0; col < N; col++) {
                for (int row = roof[col]; row < N; row++) {
                    if (board[row][col] == 0) // col에 0이 있는 만큼 내리기
                        roof[col]++;
                    else
                        break;
                }
            }
        }
    }
    cout << answer << endl;
}