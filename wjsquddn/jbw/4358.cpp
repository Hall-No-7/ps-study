#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, float> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    float cnt = 0;
    while (getline(cin, s))
    {
        // if (s == "q") // 종료 신호를 입력받으면 루프 종료
        //     break;
        cnt++;
        if (m.find(s) != m.end())
        {
            m[s] += 1;
        }
        else
        {
            m[s] = 1;
        }
    }
    cout << fixed;
    cout.precision(4);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        float a = (it->second / cnt) * 100;
        cout << it->first << " " << a << endl;
    }
}
