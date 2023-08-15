#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int TimeToInt(string str) {
    stringstream ss(str);
    string hour, minute;
    getline(ss, hour, ':');
    ss >> minute;
    return stoi(hour) * 60 + stoi(minute);
}

struct Record {
    int inTime, outTime, prevTime;
    Record() {}
    Record(string time) {
        inTime = TimeToInt(time);
        outTime = 23 * 60 + 59;
        prevTime = 0;
    }
};

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, Record> m;
    for (int i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);
        string time, number, record;
        ss >> time >> number >> record;
        if (record == "IN") {
            if (m.find(number) != m.end()) {
                int prevTime = m[number].outTime - m[number].inTime;
                m[number].prevTime +=
                    prevTime; // 시펄... 2번 들어오면 3번 4번도 가능하다
                m[number].inTime = TimeToInt(time);
                m[number].outTime = 23 * 60 + 59;
            } else
                m[number] = Record(time);

        } else
            m[number].outTime = TimeToInt(time);
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        int fee = 0;
        int time = it->second.outTime - it->second.inTime + it->second.prevTime;
        fee += fees[1];
        if (time > fees[0]) {
            time -= fees[0];
            if (time % fees[2] == 0)
                fee += time / fees[2] * fees[3];
            else
                fee += (time / fees[2] + 1) * fees[3];
        }
        answer.push_back(fee);
    }
    return answer;
}