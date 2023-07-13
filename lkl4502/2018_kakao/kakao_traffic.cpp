#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> lines;
    // lines.push_back("2016-09-15 03:10:33.020 0.011s");
    lines.push_back("2016-09-15 20:59:57.421 0.351s");
    lines.push_back("2016-09-15 20:59:58.233 1.181s");
    lines.push_back("2016-09-15 20:59:58.299 0.8s");
    lines.push_back("2016-09-15 20:59:58.688 1.041s");
    lines.push_back("2016-09-15 20:59:59.591 1.412s");
    lines.push_back("2016-09-15 21:00:00.464 1.466s");
    lines.push_back("2016-09-15 21:00:00.741 1.581s");
    lines.push_back("2016-09-15 21:00:00.748 2.31s");
    lines.push_back("2016-09-15 21:00:00.966 0.381s");
    lines.push_back("2016-09-15 21:00:02.066 2.62s");

    vector<pair<float, float>> arr;

    for (int i = 0; i < lines.size(); i++) {
        istringstream str(lines[i]);
        str.str();
        string date, time, duration;
        str >> date >> time >> duration;

        float millisec =
            (stof(time.substr(0, 2)) * 3600 + stof(time.substr(3, 2)) * 60 +
             stof(time.substr(6, 2))) *
                1000 +
            stof(time.substr(9, 3));

        duration.pop_back();

        float period = stof(duration) * 1000;

        arr.push_back(make_pair(millisec, millisec - period + 1));
    }

    cout.precision(100);

    // pair first와 second를 바꾸면 정렬시 람다 함수 작성 안해줘도됨
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i].first << " " << arr[i].second << ENDL;

    int answer = 0;
    for (int i = 0; i < arr.size(); i++) {
        int count = 1;
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j].second - arr[i].first < 1000)
                count++;
        answer = max(answer, count);
    }
    cout << answer << ENDL;
}