#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string song = "";
    map<string, int> songinformation;
    pair<string, int> p = {"", 0};
    for (int i = 0; i < m.size(); i++) {
        if (m[i + 1] >= 65 && m[i + 1] <= 90) {
            song += m[i];
        } else {
            if (i + 1 == m.size()) {
                song += (m[i]);
                break;
            }
            song += (m[i] + 32);
            i++;
        }
    }

    // cout << song << endl;
    for (int i = 0; i < musicinfos.size(); i++) {
        string s = musicinfos[i];
        string firsthour = s.substr(0, 2);
        string firstminute = s.substr(3, 2);
        string secondhour = s.substr(6, 2);
        string secondminute = s.substr(9, 2);
        int a = stoi(secondhour) * 60 + stoi(secondminute) - stoi(firsthour) * 60 - stoi(firstminute);
        string name = "";
        int j;
        for (j = 12; j < s.size(); j++) {
            if (s[j] == ',') {
                j++;
                break;
            }
            name += s[j];
        }
        string melody = "";
        // j++;
        for (; j < s.size(); j++) {
            melody += s[j];
        }
        // cout << a << " " << name << " " << melody << endl;
        string currentmelody = "";
        for (int i = 0; i < melody.size(); i++) {
            if (melody[i + 1] >= 65 && melody[i + 1] <= 90) {
                currentmelody += melody[i];
            } else {
                if (i + 1 == melody.size()) {
                    currentmelody += (melody[i]);
                    break;
                }
                currentmelody += char((melody[i] + 32));
                i++;
            }
        }
        if (a > currentmelody.size()) {
            string repeated = "";
            while (repeated.length() < a) {
                repeated += currentmelody;
            }
            currentmelody = repeated;
        }
        currentmelody = currentmelody.substr(0, a);

        // 곡의 사이즈가 더 크거나 같을때
        int idx = currentmelody.find(song);
        if (idx != -1 && p.second < a) {
            p.first = name;
            p.second = a;
        }
    }
    answer = p.first;
    if (answer == "") answer = "(None)";
    return answer;
}