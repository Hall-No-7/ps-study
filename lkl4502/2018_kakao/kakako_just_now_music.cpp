#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

struct musicInfo {
    int duration = 0;
    string title = "", score = "";
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string m = "CCB";
    vector<string> musicinfos;
    // musicinfos.push_back("12:00,12:14,HELLO,C#DEFGAB");
    // musicinfos.push_back("13:00,13:05,WORLD,ABCDEF");

    // musicinfos.push_back("03:00,03:30,FOO,CC#B");
    // musicinfos.push_back("04:00,04:08,BAR,CC#BCC#BCC#B");

    // musicinfos.push_back("12:00,12:14,HELLO,CDEFGAB");
    // musicinfos.push_back("13:00,13:05,WORLD,ABCDEF#");

    musicinfos.push_back("03:00,03:10,FOO,CCB#CCB");
    musicinfos.push_back("04:00,04:08,BAR,ABC");

    vector<musicInfo> infoArr;

    for (int i = 0; i < musicinfos.size(); i++) {
        stringstream ss(musicinfos[i]);
        string start, end, title, score;
        musicInfo mInfo;
        getline(ss, start, ',');
        getline(ss, end, ',');
        getline(ss, title, ',');
        getline(ss, score, ',');
        mInfo.duration =
            stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3)) -
            (stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3)));
        mInfo.title = title;
        int idx = 0;
        for (int k = 0; k < mInfo.duration; k++) {
            int len = (idx + 1 < score.size() && score[idx + 1] == '#') ? 2 : 1;

            mInfo.score += score.substr(idx, len);

            if (len == 1)
                idx++;
            else
                idx += 2;

            if (idx == score.size())
                idx = 0;
        }
        infoArr.push_back(mInfo);
    }

    musicInfo answer;
    for (auto it = infoArr.begin(); it != infoArr.end(); it++) {
        auto idx = it->score.find(m);
        while (idx != string::npos) {
            if (idx + m.size() < it->score.size() &&
                it->score[idx + m.size()] == '#')
                idx = it->score.find(m, idx + 1);
            else
                break;
        }
        if (idx == string::npos)
            continue;

        if (answer.duration < it->duration)
            answer = *it;
    }

    if (answer.title == "")
        cout << "(None)" << ENDL;
    else
        cout << answer.title << ENDL;
}