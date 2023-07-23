// c++ stringstream
//  C++에서 stringstream은 주어진 문자열에서 필요한 자료형에 맞는 정보를 꺼낼 때 유용하게 사용됩니다.
//  stringstream에서 공백과 '\n'을 제외하고 문자열에서 맞는 자료형의 정보를 빼냅니다.
//  ˙ #include <sstream>  전처리 헤더를 필수로 포함해야 합니다.
//  ˙ stream.str(string str) 은 현재 stream의 값을 문자열 str로 바꿉니다.
// https://life-with-coding.tistory.com/403
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer, state;
    map<string, string> user;
    for (int i = 0; i < record.size(); i++) {
        string str[3];
        string token;
        stringstream ss(record[i]);
        int index = 0;
        while (ss >> token) {
            str[index++] = token;
        }
        if (str[0] == "Enter") {
            state.push_back("님이 들어왔습니다.");
            answer.push_back(str[1]);
            user[str[1]] = str[2];
        } else if (str[0] == "Leave") {
            state.push_back("님이 나갔습니다.");
            answer.push_back(str[1]);
        } else {
            user[str[1]] = str[2];
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        answer[i] = user[answer[i]] + state[i];
    }
    return answer;
}
int main() {
    vector<string> strVector = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
    vector<string> answer;
    answer = solution(strVector);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    return 0;
}