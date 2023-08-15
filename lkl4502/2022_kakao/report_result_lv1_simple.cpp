#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> idx_m;
    map<string, set<string>> report_m;

    for (int i = 0; i < id_list.size(); i++)
        idx_m[id_list[i]] = i;

    for (int i = 0; i < report.size(); i++) {
        stringstream ss(report[i]);
        string subject, target;
        ss >> subject >> target;
        report_m[target].insert(subject);
    }
    vector<int> answer(id_list.size(), 0);
    for (auto it = report_m.begin(); it != report_m.end(); it++) {
        if (it->second.size() >= k)
            for (auto subject : it->second)
                answer[idx_m[subject]]++;
    }
    return answer;
}