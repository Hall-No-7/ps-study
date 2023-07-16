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

    cout << song << endl;
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
        cout << a << " " << name << " " << melody << endl;
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

        cout << currentmelody << " " << a << endl;
        if (a > currentmelody.size()) {
            string repeated = "";
            while (repeated.length() < a) {
                repeated += currentmelody;
            }
            currentmelody = repeated;
        }
        currentmelody = currentmelody.substr(0, a);

        cout << currentmelody << endl;
        // 곡의 사이즈가 더 크거나 같을때
        if (song.size() >= currentmelody.size()) {
            int songsize = song.size();
            for (int i = 0; i < songsize; i++) {
                song += song[i];
            }
            cout << endl;
            if (song.find(currentmelody) != std::string::npos) {
                cout << "found" << endl;
                songinformation.insert({name, a});
            } else {
                cout << "not found" << endl;
            }
        }
        // 곡의 사이즈가 작을때
        else {
            int currentsongsize = currentmelody.size();
            for (int i = 0; i < currentsongsize; i++) {
                currentmelody += currentmelody[i];
            }
            cout << endl;
            if (currentmelody.find(song) != std::string::npos) {
                cout << "found" << endl;
                songinformation.insert({name, a});
            } else {
                cout << "not found" << endl;
            }
        }
    }
    // 답 결정
    map<string, int>::iterator it;
    it = songinformation.begin();
    cout << songinformation.size();
    if (songinformation.size() == 1) {
        answer = it->first;
    } else if (songinformation.size() == 0) {
        answer = "(None)";
    } else {
        int max = 0;
        string ans;
        for (; it != songinformation.end(); it++) {
            cout << endl << it->first << " " << it->second << endl;
            if (it->second > max) {
                max = it->second;
                ans = it->first;
                cout << ans;
            }
        }
        answer = ans;
    }
    return answer;
}
int main() {
    string m = "ABCDEFG";
    vector<string> musicinfos = {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEFL"};
    // string m = "CC#BCC#BCC#BCC#B";
    // vector<string> musicinfos = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};
    // string m = "ABC";
    // vector<string> musicinfos = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};

    cout << solution(m, musicinfos);
}