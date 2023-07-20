#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int w;
unordered_set<string> words;
vector<string> board;

int main() { // 푸는중
    fast_io;
    cin >> w;
    string str;
    for (int i = 0; i < w; i++) {
        cin >> str;
        words.insert(str);
    }

    int boardNum;
    cin >> boardNum;
    cout << boardNum << endl;
    string line;
    while (boardNum--) {
        for (int i = 0; i < 4; i++) {
            cin >> line;
            board.push_back(line);
        }
    }
}