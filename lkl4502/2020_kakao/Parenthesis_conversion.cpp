#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int divide(string str) {
    int leftCnt = 0, rightCnt = 0;
    for (auto &it : str) {
        if (it == '(')
            leftCnt++;
        else
            rightCnt++;

        if (leftCnt == rightCnt)
            break;
    }
    return leftCnt + rightCnt;
}

bool isCorrectString(string str) {
    stack<char> s;
    for (auto &it : str)
        if (it == '(')
            s.push(it);
        else {
            if (s.empty())
                return false;
            else
                s.pop();
        }

    return s.empty();
}

string getAnswer(string p) {
    string u, v;
    if (p.length() == 0) // 빈문자열 리턴
        return p;

    int idx = divide(p);

    u = p.substr(0, idx);
    v = p.substr(idx);

    if (isCorrectString(u)) // 올바른 문자열이면 v에 다시 수행
        return u + getAnswer(v);
    else {
        string answer = '(' + getAnswer(v) + ')';
        for (auto &it : u.substr(1, u.length() - 2)) // u의 시작과 끝 제거
            answer += (it == '(') ? ')' : '(';
        return answer;
    }
}

int main() {
    fast_io;
    string p = "()))((()"; // p는 무조건 짝수
    cout << getAnswer(p) << endl;
}