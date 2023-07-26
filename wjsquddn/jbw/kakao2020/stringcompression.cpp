#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int i = 1; i <= s.size() / 2; i++) {
        string temp = "";
        string a = "";
        a = s.substr(0, i);
        int cnt = 1;
        for (int j = i; j < s.size(); j += i) {
            if (a == s.substr(j, i))
                cnt++;
            else {
                // cout << temp << " ";
                if (cnt > 1) {
                    temp += to_string(cnt);
                }
                temp += a;
                // cout << temp << endl;
                a = s.substr(j, i);
                cnt = 1;
            }
            // cout << temp << endl;
        }
        if (cnt > 1) temp += to_string(cnt);
        temp += a;
        // cout << temp << endl;
        if (answer > temp.size()) {
            answer = temp.size();
        }
    }
    return answer;
}
void print(string s) { cout << solution(s) << endl; }
int main() {
    print("aabbaccc");
    print("ababcdcdababcdcd");
    print("abcabcdede");
    print("abcabcabcabcdededededede");
    print("xababcdcdababcdcd");
    return 0;
}