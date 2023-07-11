#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    vector<string> v;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        string s = "";
        s += c;
        v.push_back(s);
    }
    for (int i = 0; i < msg.size(); i++)
    {
        string ss = "";
        for (int j = i; j < msg.size(); j++)
        {

            ss += msg[j];
            vector<string>::iterator it = find(v.begin(), v.end(), ss);
            // 못 찾았을 때
            if (it == v.end())
            {
                v.push_back(ss);
                ss.pop_back();
                int check = 0;
                for (int k = 0; k < v.size(); k++)
                {
                    if (v[k] == ss)
                    {
                        answer.push_back(k + 1);
                        check = 1;
                        break;
                    }
                }
                if (check == 1)
                {

                    i = ss.size() + i - 1;
                    break;
                }
            }
            else
            {
                if (i + ss.size() == msg.size())
                {
                    for (int k = 0; k < v.size(); k++)
                    {
                        if (v[k] == ss)
                        {
                            answer.push_back(k + 1);
                            i = ss.size() + i - 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return answer;
}

int main()
{
    string msg = "TOBEORNOTTOBEORTOBEORNOT";
    vector<int> answer = solution(msg);
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}