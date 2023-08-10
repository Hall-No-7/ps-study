// By Hongs
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
    if (p1.first.length() == p2.first.length())
        return p1.second > p2.second;
    return p1.first.length() < p2.first.length();
}

int main() {
    vector<string> orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    vector<int> course = {2, 3, 5};

    map<string, int> m;

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
                m[combi]++;
            } while (next_permutation(visit.begin(), visit.end()));
        }
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    vector<string> answer;
    int maxCnt = v[0].second, len = v[0].first.length();
    for (auto &it : v) {
        if (it.second < 2)
            continue;
        if (len == it.first.length()) {
            if (maxCnt > it.second)
                continue;
            answer.push_back(it.first);
        } else {
            maxCnt = it.second;
            len = it.first.length();
            answer.push_back(it.first);
        }
    }
    sort(answer.begin(), answer.end());
    for (auto &it : answer)
        cout << it << endl;
}