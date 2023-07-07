#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int height = 6, width = 6, answer = 0;
    vector<string> board = {"TTTANT", "RRFACC", "RRRFCC",
                            "TRRRAA", "TTMMMF", "TMMTTJ"};
    vector<pair<int, int>> arr;
    do {
        arr.clear();
        vector<pair<int, int>>().swap(arr);
        for (int y = 0; y < height - 1; y++) {
            for (int x = 0; x < width - 1; x++) {
                if (board[y][x] != '0' && board[y][x] == board[y + 1][x] &&
                    board[y][x] == board[y][x + 1] &&
                    board[y][x] == board[y + 1][x + 1]) {
                    arr.push_back(make_pair(y, x));
                    arr.push_back(make_pair(y + 1, x));
                    arr.push_back(make_pair(y, x + 1));
                    arr.push_back(make_pair(y + 1, x + 1));
                }
            }
        }

        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        cout << arr.size() << ENDL;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++)
                cout << board[y][x] << ' ';
            cout << ENDL;
        }

        cout << "------------" << ENDL;

        for (int i = 0; i < arr.size(); i++) {
            board[arr[i].first][arr[i].second] = '0';
        }

        for (int x = 0; x < width; x++) {
            for (int y = height - 1; y >= 0; y--) {
                if (board[y][x] == '0')
                    continue;
                int dropHeight = 1;
                for (; y + dropHeight < height; dropHeight++) {
                    if (board[y + dropHeight][x] == '0')
                        continue;
                    break;
                }

                if (--dropHeight > 0)
                    swap(board[y][x], board[y + dropHeight][x]);
            }
        }

        answer += arr.size();
    } while (arr.size() != 0);

    cout << answer << ENDL;
}