// By Hongs
#include <string>
#include <vector>
using namespace std;

int TimeToInt(string str) {
    string hour = str.substr(0, 2);
    string minute = str.substr(3, 2);
    string sec = str.substr(6, 2);
    return stoi(hour) * 3600 + stoi(minute) * 60 + stoi(sec);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playTime = TimeToInt(play_time);
    int advTime = TimeToInt(adv_time);
    vector<int> watchTime(playTime, 0);

    for (auto &log : logs) {
        int start = TimeToInt(log.substr(0, 8));
        int end = TimeToInt(log.substr(9));
        for (int i = start; i < end; i++)
            watchTime[i]++;
    }

    int start = 0;
    long long sum = 0, maxSum = 0;
    for (int i = 0; i < playTime; i++) {
        if (i < advTime) {
            sum += watchTime[i];
            maxSum = sum;
            continue;
        }
        sum = sum - watchTime[i - advTime] + watchTime[i];
        if (maxSum < sum) { // 다음 것을 더한것이 더 클때
            start = i - advTime + 1;
            maxSum = sum;
        }
    }
    int hour = start / 3600;
    int minute = start % 3600 / 60;
    int sec = start % 60;
    answer += ((hour < 10) ? "0" + to_string(hour) : to_string(hour)) + ":";
    answer +=
        ((minute < 10) ? "0" + to_string(minute) : to_string(minute)) + ":";
    answer += (sec < 10) ? "0" + to_string(sec) : to_string(sec);
    return answer;
}