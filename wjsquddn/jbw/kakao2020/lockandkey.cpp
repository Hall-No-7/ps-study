#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m;
bool checkinsert(vector<vector<int>> MAP) {
    for (int i = n - 1; i < n + m - 1; i++) {
        for (int j = n - 1; j < n + m - 1; j++) {
            // 돌기끼리 만났을 때를 처리를 안해서 testcase 23,25,33틀림
            if (MAP[i][j] == 0 || MAP[i][j] > 1) return false;
        }
    }
    return true;
}
void rotatekey(vector<vector<int>> &key) {
    vector<vector<int>> temp = key;
    int len = key.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            temp[i][j] = key[len - 1 - j][i];
        }
    }
    key = temp;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    n = key.size();
    m = lock.size();
    int mapsize = 2 * (n - 1) + m;
    vector<vector<int>> MAP(mapsize, vector<int>(mapsize, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            MAP[n + i - 1][n + j - 1] = lock[i][j];
        }
    }
    // for (int i = 0; i < mapsize; i++) {
    //     for (int j = 0; j < mapsize; j++) {
    //         cout << MAP[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int rotate = 0; rotate < 4; rotate++) {
        for (int i = 0; i < n + m - 1; i++) {
            for (int j = 0; j < n + m - 1; j++) {
                vector<vector<int>> CNT = MAP;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        CNT[k + i][l + j] += key[k][l];
                    }
                }
                // if (rotate == 1) {
                //     for (int i = 0; i < mapsize; i++) {
                //         for (int j = 0; j < mapsize; j++) {
                //             cout << CNT[i][j];
                //         }
                //         cout << endl;
                //     }
                //     cout << endl;
                // }

                if (checkinsert(CNT)) return true;
            }
        }
        rotatekey(key);
    }
    answer = false;
    return answer;
}
int main() {
    vector<vector<int>> key = {{0, 0, 1}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    cout << solution(key, lock);
}