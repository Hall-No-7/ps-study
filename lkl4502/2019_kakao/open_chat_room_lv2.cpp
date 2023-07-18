#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int main() {
    fast_io;
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo",
                             "Leave uid1234", "Enter uid1234 Prodo",
                             "Change uid4567 Ryan"};

    map<string, string> userInfo;

    vector<string> userId, action, answer;

    string enter = "님이 들어왔습니다.", leave = "님이 나갔습니다.";
    for (int i = 0; i < record.size(); i++) {
        istringstream iss(record[i]);
        iss.str();
        string act, id, name;
        iss >> act >> id >> name;

        switch (act[0]) {
        case 'C':
            userInfo[id] = name;
            break;
        case 'E':
            userInfo[id] = name;
            action.push_back(enter);
            userId.push_back(id);
            break;
        case 'L':
            action.push_back(leave);
            userId.push_back(id);
            break;
        }
    }

    for (auto it = userInfo.begin(); it != userInfo.end(); it++)
        cout << it->first << " " << it->second << endl;

    for (int i = 0; i < action.size(); i++)
        answer.push_back(userInfo[userId[i]] + action[i]);

    for (auto it = answer.begin(); it != answer.end(); it++)
        cout << *it << endl;
}