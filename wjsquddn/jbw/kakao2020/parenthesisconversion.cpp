#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
bool checkstring(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push('(');
        } else {
            if (st.size() == 0) return false;
            st.pop();
        }
    }
    if (st.size() == 0)
        return true;
    else {
        return false;
    }
}
string solution(string p) {
    string answer = "";
    //  1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if (p == "") return "";
    // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.
    // 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며,
    // v는 빈 문자열이 될 수 있습니다.
    string u, v;
    int left = 0, right = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            left++;
        else
            right++;
        if (right == left) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    // 3. 문자열 u가 "올바른 괄호 문자열" 이라면
    // 문자열 v에 대해 1단계부터 다시 수행합니다.
    if (checkstring(u)) {
        v = solution(v);
        answer = u + v;
        //   3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
        return answer;
    }
    // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
    else {
        string cnt = "";
        cnt += '(';
        cnt += solution(v);
        cnt += ')';
        for (int j = 0; j < u.size(); j++) {
            if (j == 0 || j == u.size() - 1) continue;
            if (u[j] == '(')
                cnt += ')';
            else {
                cnt += '(';
            }
        }
        return cnt;
    }
    //   4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
    //   4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
    //   4-3. ')'를 다시 붙입니다.
    //   4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
    //   4-5. 생성된 문자열을 반환합니다.

    return answer;
}

int main() { cout << solution("(()())()"); }