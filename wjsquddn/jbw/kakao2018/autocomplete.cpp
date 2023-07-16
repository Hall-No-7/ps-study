#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Trie {
    int count = 0;
    Trie* node[26];
    Trie() {
        for (int i = 0; i < 26; i++) {
            node[i] = NULL;
        }
        count = 0;
    }
    void insert(string& s, int idx) {
        count++;
        if (idx == s.size()) {
            return;
        }
        if (node[s[idx] - 'a'] == NULL) {
            node[s[idx] - 'a'] = new Trie();
        }
        node[s[idx] - 'a']->insert(s, idx + 1);
    }
    int AutoComplete(string str) {
        int num = 1;
        Trie* now = node[str[0] - 'a'];
        for (int i = 1; i < str.size(); i++) {
            if (now->count > 1) {
                num++;
            }
            now = now->node[str[i] - 'a'];
        }
        return num;
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie* root = new Trie();
    for (string word : words) {
        root->insert(word, 0);
    }
    for (string word : words) {
        answer += root->AutoComplete(word);
    }
    return answer;
}

int main() {
    vector<string> strVector = {"go", "gone", "guild"};
    cout << solution(strVector);
    return 0;
}