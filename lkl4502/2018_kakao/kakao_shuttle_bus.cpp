#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

string transTime(int time) {
    string timeStr = "";
    if (time / 60 < 10)
        timeStr += "0";
    timeStr += to_string(time / 60);
    timeStr += ":";
    if (time % 60 < 10)
        timeStr += "0";
    timeStr += to_string(time % 60);
    return timeStr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 10, t = 60, m = 45;
    vector<string> timetable; // HH:MM 형싱이고 00:01 ~ 23:59 가능
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");
    timetable.push_back("23:59");

    vector<int> crewArrive;
    string hour, minute;
    for (int i = 0; i < timetable.size(); i++) {
        stringstream ss(timetable[i]);
        getline(ss, hour, ':');
        getline(ss, minute, ':');
        crewArrive.push_back(stoi(hour) * 60 + stoi(minute));
    }

    sort(crewArrive.begin(), crewArrive.end());

    int shuttleTime = 60 * 9, crewCnt = 0, answer;
    for (int i = 0; i < n; i++) {
        int idx = 0;
        for (int k = crewCnt; k < crewArrive.size(); k++) {
            if (crewArrive[k] <= shuttleTime) {
                crewCnt++, idx++;
                if (idx == m)
                    break;
            }
        }
        if (i + 1 == n) {
            if (idx == m)
                answer = crewArrive[crewCnt - 1];
            else
                answer = shuttleTime;
        }
        shuttleTime += t;
    }
    cout << answer << ENDL;
    cout << transTime(answer) << ENDL;
}