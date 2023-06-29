#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n = 0;

vector<string> v;

vector<int> ans;
int visited[10];

vector<vector<int> > last;

void makeCombination(int cnt) {
    if (cnt == n) {
        last.push_back(ans);
        return;
    }

    string symbol = v[cnt];

    for (int i = 0; i < 10; i++) {
        if (visited[i]) continue;

        if (symbol == "<" && ans[cnt] < i) {
            ans.push_back(i);
            visited[i] = 1;
            makeCombination(cnt + 1);
            ans.pop_back();
            visited[i] = 0;
        } else if (symbol == ">" && ans[cnt] > i) {
            ans.push_back(i);
            visited[i] = 1;
            makeCombination(cnt + 1);
            visited[i] = 0;
            ans.pop_back();
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < 10; i++) {
        ans.push_back(i);
        visited[i] = 1;
        makeCombination(0);
        ans.pop_back();
        visited[i] = 0;
    }

    vector<int> tmp;
    int ll = last.size();
    tmp = last[ll - 1];
    for (int i = 0; i < tmp.size(); i++) {
        cout << tmp[i];
    }
    cout << '\n';
    tmp = last[0];

    for (int i = 0; i < tmp.size(); i++) {
        cout << tmp[i];
    }

    return 0;
}
