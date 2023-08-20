#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, set<string>> dosingo;
    map<string, int> name;
    for (int i = 0; i < id_list.size(); i++) {
        name[id_list[i]] = i;
    }
    // for(int i=0;i<id_list.size();i++){
    //     dosingo[id_list[i]] = 0;
    //     getsingo[id_list[i]] = 0;
    // }
    for (auto rep : report) {
        stringstream ss(rep);
        string a, b;
        ss >> a >> b;
        dosingo[b].insert(a);
    }
    for (auto iter : dosingo) {
        if (iter.second.size() >= k) {
            for (auto it : iter.second) {
                // cout << it;
                answer[name[it]]++;
            }
        }
    }

    return answer;
}
int main() {
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
    int k = 2;
    vector<int> aa = solution(id_list, report, k);
    for (int i = 0; i < aa.size(); i++) {
        cout << aa[i] << " ";
    }
}