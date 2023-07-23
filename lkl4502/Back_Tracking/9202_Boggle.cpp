#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int w;
set<string> findWords;
vector<string> board, words;
string word, answer;
bool visited[4][4];
bool flag = false;

int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void FindWord(
    int row, int col, int idx,
    int len) { // idx 현재까지 찾고 있는 단어를 어디까지 찾았는지를 가지고 있음
    if (idx == len) {
        findWords.insert(answer);
        flag = true;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int newR = row + dr[i], newC = col + dc[i];
        if (flag) // 해당 단어를 찾았으면 다음 단어로 가기 위해서 반복문 종료
            break;
        if (newR < 0 || newR > 3 || newC < 0 || newC > 3) // 보드 범위 확인
            continue;
        if (visited[newR][newC]) // 방문했다면 다음 진행
            continue;
        if (board[newR][newC] != word[idx]) // 다르면 갈 필요 X
            continue;
        // 다 걸렀으면 다음으로 진행
        answer += word[idx];
        visited[newR][newC] = true;
        FindWord(newR, newC, idx + 1, len);
        visited[newR][newC] = false;
        answer.pop_back();
    }
}

void Print() {
    int sum = 0;
    string longest;
    for (auto &it : findWords) {
        if (longest.length() < it.length())
            longest = it;
        sum += score[it.length()];
    }
    cout << sum << " " << longest << " " << findWords.size() << endl;
}

int main() { // 푸는중
    fast_io;
    cin >> w;
    string str;
    for (int i = 0; i < w; i++) {
        cin >> str;
        words.push_back(str);
    }

    int boardNum;
    cin >> boardNum;
    string line;
    while (boardNum--) {
        for (int i = 0; i < 4; i++) {
            cin >> line;
            board.push_back(line);
        }

        for (int i = 0; i < words.size(); i++) {
            word = words[i];
            for (int i = 0; i < 16; i++) {
                if (flag)
                    break;
                if (board[i / 4][i % 4] == word[0]) {
                    answer += word[0];
                    visited[i / 4][i % 4] = true;
                    FindWord(i / 4, i % 4, 1, word.length());
                    visited[i / 4][i % 4] = false;
                    answer.pop_back();
                }
            }
            flag = false;
        }

        Print();

        findWords.clear();
        board.clear();
    }
}