#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
    if (p1.first.length() == p2.first.length())
        return p1.first < p2.first;
    return p1.first.length() < p2.first.length();
}

int main() {
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2, 3, 4};
    vector<set<char>> tmp;
    vector<pair<string, int>> answer;
    for (auto &menus : orders) {
        set<char> s;
        for (auto &menu : menus)
            s.insert(menu);
        tmp.push_back(s);
    }

    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        for (int j = 0; j < course.size(); j++) {
            if (course[j] > orders[i].length())
                continue;
            vector<int> visit(orders[i].length(), 1);
            for (int idx = 0; idx < orders[i].length() - course[j]; idx++)
                visit[idx] = 0;
            do { // 조합 찾기
                string combi;
                for (int k = 0; k < orders[i].size(); k++)
                    if (visit[k] != 0)
                        combi += orders[i][k];
                int cnt = 0;
                for (int k = 0; k < tmp.size(); k++) {
                    int len = 0;
                    for (auto &ch : combi) {
                        if (tmp[k].find(ch) == tmp[k].end())
                            break;
                        len++;
                    }
                    if (len == combi.length())
                        cnt++;
                }
                if (cnt >= 2)
                    answer.push_back(make_pair(combi, cnt));
            } while (next_permutation(visit.begin(), visit.end()));
        }
    }
    vector<string> result;
    set<string> s;
    sort(answer.begin(), answer.end(), cmp);
    int maxCnt = 0;
    string maxStr;

    for (int i = 0; i < answer.size(); i++) {
        if (maxCnt <= answer[i].second) {
            maxCnt = answer[i].second;
            if (maxStr != answer[i].first)
                result.push_back(answer[i].first);
            maxStr = answer[i].first;
        }
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i].first << " " << answer[i].second << endl;
}