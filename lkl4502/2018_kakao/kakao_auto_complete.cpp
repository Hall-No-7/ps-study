#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

class Trie {
  public:
    Trie() {
        isFinsih = false;
        for (int i = 0; i < 26; i++)
            node[i] = NULL;
    }
    int children = 1;
    bool isFinsih;
    Trie *node[26]; // a ~ z

    void insert(const char *ch) {
        if (*ch == '\0') {
            isFinsih = true;
            return;
        }
        int idx = *ch - 97;
        if (node[idx] == NULL)
            node[idx] = new Trie();
        else
            node[idx]->children++;
        node[idx]->insert(ch + 1);
    }

    bool find(const char *ch, int &cnt) {
        if (*ch == '\0') {
            cnt--;
            return true;
        }
        int idx = *ch - 97;
        if (node[idx] == NULL)
            return false;
        if (node[idx]->children == 1)
            return true;
        cnt++;
        return node[idx]->find(ch + 1, cnt);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> words;
    words.push_back("word");
    words.push_back("war");
    words.push_back("warrior");
    words.push_back("world");
    Trie *root = new Trie();

    for (int i = 0; i < words.size(); i++) {
        root->insert(words[i].c_str());
    }

    int answer = 0;
    for (int i = 0; i < words.size(); i++) {
        int cnt = 1;
        root->find(words[i].c_str(), cnt);
        answer += cnt;
    }
    cout << answer << ENDL;
}