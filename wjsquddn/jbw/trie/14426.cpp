#include <iostream>
using namespace std;
struct Trie
{
    Trie *node[26];
    // 생성자
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            node[i] = NULL;
        }
    }
    // insert
    void insert(string &s, int idx)
    {
        // 종료조건
        if (idx == s.size())
        {
            return;
        }
        if (node[s[idx] - 'a'] == NULL)
        {
            node[s[idx] - 'a'] = new Trie();
        }
        node[s[idx] - 'a']->insert(s, idx + 1);
    }
    // find
    bool find(string &s, int idx)
    {
        // 성공
        if (s.size() == idx)
        {
            return true;
        }
        // 실패
        if (node[s[idx] - 'a'] == NULL)
            return false;
        return node[s[idx] - 'a']->find(s, idx + 1);
    }
    // 소멸자
    void clear()
    {
        for (int i = 0; i < 26; i++)
        {
            if (node[i] != NULL)
            {
                node[i]->clear();
                delete node[i];
            }
        }
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    Trie *root = new Trie();
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        root->insert(s, 0);
    }
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (root->find(s, 0))
            answer++;
    }
    cout << answer;
    return 0;
}