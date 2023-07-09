#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Trie
{
    Trie *node[10];
    // 생성자
    Trie()
    {
        for (int i = 0; i < 10; i++)
        {
            node[i] = NULL;
        }
    }
    // insert
    void insert(string &s, int idx)
    {
        if (idx == s.size())
        {
            return;
        }
        if (node[s[idx] - '0'] == NULL)
        {
            node[s[idx] - '0'] = new Trie();
        }
        node[s[idx] - '0']->insert(s, idx + 1);
    }

    // find
    bool find(string &s, int idx)
    {
        if (s.size() == idx)
        {
            return true;
        }
        if (node[s[idx] - '0'] == NULL)
            return false;
        return node[s[idx] - '0']->find(s, idx + 1);
    }
    // 소멸자
    void clear()
    {
        for (int i = 0; i < 10; i++)
        {
            if (node[i] != NULL)
            {
                node[i]->clear();
                delete node[i];
                node[i] = NULL;
            }
        }
    }
};
bool compare(string a, string b)
{
    return a.size() > b.size();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        Trie *root = new Trie();
        vector<string> v;
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        // vector를 string 크기 큰 순서대로 저장
        sort(v.begin(), v.end(), compare);
        int answer = 0;
        int check = 0;
        int doublecheck = 0;
        for (int i = 0; i < v.size(); i++)
        {
            // if (root->insert(v[i], 0) == true)
            //     cnt++;
            check = root->find(v[i], 0);
            root->insert(v[i], 0);
            if (check == 1)
            {
                doublecheck = 1;
                break;
            }
        }
        if (doublecheck == 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
        }
        root->clear();
    }
}

// 기존 코드 문제점 insert 할 때 bool 타입으로 설정함
//  clear 시에 delete를 하고 널 타입으로 바꾸어 주었어야 한다.