#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> answer;
    string msg = "TOBEORNOTTOBEORTOBEORNOT";

    vector<string> dict;

    // dict 초기화
    for (char ch = 'A'; ch <= 'Z'; ch++)
        dict.push_back(string(1, ch));

    while (msg != "") {
        string str;
        int idx = 0;
        str += msg[idx++];
        int print;
        auto it = find(dict.begin(), dict.end(), str);
        while (it != dict.end()) {
            print = it - dict.begin() + 1;
            str += msg[idx++];
            it = find(dict.begin(), dict.end(), str);
        }
        answer.push_back(print);
        dict.push_back(str);
        msg = msg.substr(str.size() - 1);
    }

    for (auto it = answer.begin(); it != answer.end(); it++)
        cout << *it << ENDL;
}