#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> lines)
{
    int answer = 0;
    vector<int> start, end;
    for (int i = 0; i < lines.size(); i++)
    {
        string h, m, s, ms;
        int hh, mm, ss, process;
        lines[i].pop_back();
        h = lines[i].substr(11, 2);
        m = lines[i].substr(14, 2);
        s = lines[i].substr(17, 2);
        ms = lines[i].substr(20, 3);
        process = stof(lines[i].substr(24, 5)) * 1000;
        hh = stoi(h) * 3600 * 1000;
        mm = stoi(m) * 60 * 1000;
        ss = stoi(s) * 1000 + stoi(ms);
        start.push_back(hh + mm + ss - process + 1);
        end.push_back(hh + mm + ss);
    }
    for (int i = 0; i < lines.size(); i++)
    {
        int endtime = end[i] + 1000;
        int cnt = 0;
        for (int j = i; j < lines.size(); j++)
        {
            if (start[j] < endtime)
            {
                cnt++;
            }
            if (cnt > answer)
                answer = cnt;
        }
    }

    return answer;
}
int main()
{
    vector<std::string> strVector = {
        "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.299 0.8s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
        "2016-09-15 21:00:02.066 2.62s"};
    cout << solution(strVector);
}