#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<int>> m;
    for (auto re : records) {
        string hour = re.substr(0, 2);
        string minute = re.substr(3, 2);
        int cnt = stoi(hour) * 60 + stoi(minute);
        string name = re.substr(6, 4);
        m[name].push_back(cnt);
    }
    vector<string> s;
    for (auto it : m) {
        s.push_back(it.first);
    }
    sort(s.begin(), s.end());
    for (auto ss : s) {
        int cnt = 0;
        int i = 0;
        for (; i < m[ss].size() / 2; i++) {
            cnt += m[ss][i * 2 + 1] - m[ss][i * 2];
        }
        // cout << cnt << " ";
        if (m[ss].size() % 2 == 1) {
            cnt += 1439 - m[ss][m[ss].size() - 1];
        }
        // cout << cnt << endl;
        int fee = 0;
        if (cnt < fees[0]) {
            fee = fees[1];
        } else {
            cnt = cnt - fees[0];
            fee = fees[1];
            fee += (cnt / fees[2]) * fees[3];
            if (cnt % fees[2] > 0) {
                fee += fees[3];
            }
        }
        // cout << fee << " ";
        answer.push_back(fee);
    }

    return answer;
}
int main() {
    vector<int> fees = {180, 5000, 10, 600};
    vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};

    vector<int> result = solution(fees, records);
    // cout << endl;
    for (int fee : result) {
        cout << fee << " ";
    }

    return 0;
}