#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    // 분 형식으로 바꾸어서 timetable_int에 넣어주기
    sort(timetable.begin(), timetable.end());
    vector<int> timetable_int;
    string hh = "", mm = "";
    int result_int = 0;
    for (int i = 0; i < timetable.size(); i++) {
        int cnt = 0;
        hh = timetable[i].substr(0, 2);
        mm = timetable[i].substr(3, 2);
        cnt = stoi(hh) * 60 + stoi(mm);
        timetable_int.push_back(cnt);
    }
    // 이제 버스 시간 계산
    int bus_start = 540;
    int vector_cnt = 0;
    // 버스가 올때까지 계산
    for (int i = 0; i < n; i++) {
        int getoncount = 0;  // 버스에 타고 있는 사람
        while (getoncount < m && vector_cnt < timetable_int.size()) {
            if (timetable_int[vector_cnt] <= bus_start) {
                getoncount++;
                vector_cnt++;
            } else {
                break;
            }
        }
        // 버스에 사람을 다 태우고 여유로웠는지 확인하기
        if (i == (n - 1)) {
            if (getoncount < m) {
                result_int = bus_start;
            } else {
                result_int = timetable_int[vector_cnt - 1] - 1;
            }
        }
        bus_start += t;
    }
    int h, minute;
    h = result_int / 60;
    minute = result_int % 60;
    if (h < 10) {
        answer += "0";
        answer += to_string(h);
    } else {
        answer += to_string(h);
    }
    answer += ":";
    if (minute < 10) {
        answer += "0";
        answer += to_string(minute);
    } else {
        answer += to_string(minute);
    }

    return answer;
}

int main() {
    vector<std::string> strVector = {"08:00", "08:01", "08:02", "08:03"};
    int n = 1;
    int t = 1;
    int m = 5;
    cout << solution(n, t, m, strVector);
    return 0;
}