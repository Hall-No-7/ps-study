#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, pair<int, set<string>>> m1;
    map<string, pair<int, int>> answer; // first -> idx, second -> cnt
    for (int i = 0; i < id_list.size(); i++) {
        m1[id_list[i]] = {0, set<string>()};
        answer[id_list[i]] = {i, 0};
    }

    for (int i = 0; i < report.size(); i++) {
        int len = report[i].find(" ");
        string subject = report[i].substr(0, len);
        string target = report[i].substr(len + 1);
        if (m1[target].second.find(subject) != m1[target].second.end())
            continue;
        m1[target].first++;
        m1[target].second.insert(subject);
    }

    for (auto it = m1.begin(); it != m1.end(); it++) {
        if (it->second.first >= k) {
            for (auto subject = it->second.second.begin();
                 subject != it->second.second.end(); subject++)
                answer[*subject].second++;
        }
    }
    vector<int> result(id_list.size());
    for (auto it = answer.begin(); it != answer.end(); it++)
        result[it->second.first] = it->second.second;

    return result;
}