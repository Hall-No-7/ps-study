#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

void Rotate(vector<vector<int>> &key, int keySize) {
    vector<vector<int>> tmp(keySize, vector<int>(keySize, 0));
    for (int i = 0, col = keySize - 1; i < keySize; i++, col--)
        for (int j = 0, row = 0; j < keySize; j++, row++)
            tmp[row][col] = key[i][j];
    key = tmp;
}

int main() {
    fast_io;
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    int answer = 0;
    int keySize = key.size(), lockSize = lock.size();
    /*
     기본 상태, 90도, 180도 270도 회전했을 때를 확인, 4번
    4가지의 상태에서 상하좌우로 좌표를 이동해 완전탐색을 목표로
    lock에 key값을 더해서 lock원소를 모두 더햇을 때 lockSize*lockSize가
    나와야함.
    */

    vector<vector<int>> bigLock(lockSize + 2 * (keySize - 1),
                                vector<int>(lockSize + 2 * (keySize - 1), 0));

    for (int i = keySize - 1; i < lockSize + keySize - 1; i++) {
        for (int j = keySize - 1; j < lockSize + keySize - 1; j++)
            bigLock[i][j] = lock[i - keySize + 1][j - keySize + 1];
    }

    for (int rotate = 0; rotate < 4; rotate++) { // 회전
        for (int row = 0; row < bigLock.size() - keySize + 1; row++) {
            for (int col = 0; col < bigLock.size() - keySize + 1; col++) {
                for (int keyRow = 0; keyRow < keySize; keyRow++)
                    for (int keyCol = 0; keyCol < keySize; keyCol++)
                        bigLock[row + keyRow]
                               [col + keyCol] += // key값을 bigLock에 더해준다.
                            key[keyRow][keyCol];
                for (int lockRow = keySize - 1;
                     lockRow < keySize + lockSize - 1; lockRow++)
                    for (int lockCol = keySize - 1;
                         lockCol < keySize + lockSize - 1; lockCol++)
                        if (bigLock[lockRow][lockCol] == 1) // lock 값 확인
                            answer++;
                if (answer == lockSize * lockSize) // 자물쇠를 풀었음.
                    return true;
                for (int keyRow = 0; keyRow < keySize;
                     keyRow++) // key값을 bigLock에서 다시 빼준다.
                    for (int keyCol = 0; keyCol < keySize; keyCol++)
                        bigLock[row + keyRow][col + keyCol] -=
                            key[keyRow][keyCol];
                answer = 0;
            }
        }
        Rotate(key, keySize);
    }
    return false;
}
