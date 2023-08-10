#include <iostream>
#include <regex>
#include <string>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int main() {
    fast_io;
    string new_id = "...!@BaT#*..y.abcdefghijklm";
    // 1. 소문자 변환
    for (auto &ch : new_id)
        ch = tolower(ch);
    // 2. 소문자, 숫자, -, _, . 빼고 모든 문자 제거
    for (int i = 0; i < new_id.length(); i++) {
        char ch = new_id[i];
        if (isdigit(ch) || isalpha(ch) || ch == '-' || ch == '_' || ch == '.')
            continue;
        new_id.erase(new_id.begin() + i--);
    }
    // 3. 연속되는 . 1개로 치환
    new_id = regex_replace(new_id, regex("[.]+"), ".");
    // 4. 시작과 끝이 .이면 제거
    if (new_id.front() == '.')
        new_id = new_id.substr(1);
    if (new_id.back() == '.')
        new_id = new_id.substr(0, new_id.length() - 1);
    // 5. 빈 문자열이면 "a"
    if (new_id == "")
        new_id = "a";
    // 6. 16자 이상이면 15자까지 짜르고 마지막 . 이면 제거
    if (new_id.length() >= 16)
        new_id = (new_id.substr(0, 15).back() == '.') ? new_id.substr(0, 14)
                                                      : new_id.substr(0, 15);
    // 7. 2자 이하면 마지막 문자를 길이 3까지 반복
    if (new_id.length() <= 2)
        while (new_id.length() != 3)
            new_id += new_id.back();
    cout << new_id << endl;
    // return new_id;
}