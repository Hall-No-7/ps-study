#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;
#define MAX_ALPHABET 15

int L, C, vowelCnt, consonantCnt; // vowel -> 모음 , consonants -> 자음
string password;
char alphabet[MAX_ALPHABET];
unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
bool visited[MAX_ALPHABET] = {false};

void BackTracking(int cnt, int idx) {
    if (cnt == L) {
        if (vowelCnt >= 1 && consonantCnt >= 2)
            cout << password << endl;
        return;
    }

    for (int i = idx; i < C; i++) {
        if (!visited[i]) {
            visited[i] = true;
            password += alphabet[i];
            bool flag = vowels.find(alphabet[i]) != vowels.end();
            if (flag) // if문으로 들어가면 모음이라는 뜻
                vowelCnt++;
            else
                consonantCnt++;
            BackTracking(cnt + 1, i + 1);
            if (flag) // if문으로 들어가면 모음이라는 뜻
                vowelCnt--;
            else
                consonantCnt--;
            password.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    fast_io;
    cin >> L >> C;
    char ch;
    for (int i = 0; i < C; i++) {
        cin >> ch;
        alphabet[i] = ch;
    }

    sort(alphabet, alphabet + C);

    BackTracking(0, 0);
}