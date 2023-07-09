#include <string>
#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    if (cacheSize == 0)
    {
        return cities.size() * 5;
    }
    for (string &str : cities)
    {
        for (char &c : str)
        {
            c = tolower(c);
        }
    }
    int answer = 0;
    deque<string> d(cacheSize);
    for (int i = 0; i < cities.size(); i++)
    {
        // 캐시 안에 있는지 확인하기
        int find = 0;
        deque<string>::iterator it;
        for (it = d.begin(); it != d.end(); it++)
        {
            if (*it == cities[i])
            {
                find = 1;
                break;
            }
        }
        if (find == 1)
        {
            // 캐시 안에서 어디있는지 찾고 앞에다가 넣어준다.
            string s;
            s = *it;
            d.erase(it);
            d.push_back(s);
            answer += 1;
        }
        else
        {
            d.pop_front();
            d.push_back(cities[i]);
            answer += 5;
        }
    }
    return answer;
}
int main()
{
    vector<string> strVector = {
        "Jeju", "Pangyo", "NewYork", "newyork"};
    int cacheSize = 2;
    cout << solution(cacheSize, strVector);
    return 0;
}