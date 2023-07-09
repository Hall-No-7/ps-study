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
        node[idx]->insert(ch + 1);
    }

    bool find(const char *ch) {
        if (*ch == '\0') {
            return true;
        }
        int idx = *ch - 97;
        if (node[idx] == NULL)
            return false;
        return node[idx]->find(ch + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    Trie *root = new Trie();
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        root->insert(str.c_str());
    }

    int count = 0;
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (root->find(str.c_str()))
            count++;
    }
    cout << count << ENDL;
}