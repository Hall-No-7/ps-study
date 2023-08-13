#include <iostream>
#include <string>
#include <vector>
using namespace std;

int stringtoint(string s) {
    string hh = s.substr(0, 2);
    string mm = s.substr(3, 2);
    string ss = s.substr(6, 2);
    int hour = stoi(hh) * 3600;
    int minute = stoi(mm) * 60;
    int second = stoi(ss);
    return hour + minute + second;
}
string inttostring(int a) {
    string s = "";
    int hour = a / 3600;
    int minute = (a % 3600) / 60;
    int second = a % 60;
    if (hour < 10) s += '0';
    s += to_string(hour);
    s += ':';
    if (minute < 10) s += '0';
    s += to_string(minute);
    s += ':';
    if (second < 10) s += '0';
    s += to_string(second);

    return s;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int ptime = stringtoint(play_time);
    int atime = stringtoint(adv_time);
    vector<int> starttime;
    vector<int> endtime;
    vector<int> playtime(360000, 0);
    for (int i = 0; i < logs.size(); i++) {
        int start = stringtoint(logs[i].substr(0, 8));
        int end = stringtoint(logs[i].substr(9, 8));
        starttime.push_back(start);
        endtime.push_back(end);
        for (int j = start + 1; j <= end; j++) {
            playtime[j]++;
        }
    }
    long long Cur_Play_Time = 0;
    long long Max_Play_Time = 0;
    int Time = 1;
    for (int i = 1; i <= atime; i++) {
        Cur_Play_Time += playtime[i];
        Max_Play_Time += playtime[i];
    }
    for (int i = 2; i <= (ptime - atime + 1); i++) {
        Cur_Play_Time += (long long)(playtime[i + atime - 1] - playtime[i - 1]);
        if (Cur_Play_Time > Max_Play_Time) {
            Max_Play_Time = Cur_Play_Time;
            Time = i;
        }
    }
    answer = inttostring(Time - 1);
    return answer;
}
int main() {
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};
    cout << solution(play_time, adv_time, logs);
}