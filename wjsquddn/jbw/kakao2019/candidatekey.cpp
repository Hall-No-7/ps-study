// 하다가 스트레스 받아서 비트마스킹으로 푸는 방법 찾아봄
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
bool checkvalidation(vector<int> vec, int now) {
    for (int i = 0; i < vec.size(); i++) {
        if ((vec[i] & now) == vec[i]) return false;
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();     // 6
    int col = relation[0].size();  // 4
    vector<int> ans;
    //<<은 비트 바스킹 col이 4 즉 100이므로 왼쪽으로 한칸 옮기면 8이된다.
    for (int i = 1; i < (1 << col); i++) {
        set<string> s;
        for (int j = 0; j < row; j++) {
            string now = "";
            for (int k = 0; k < col; k++) {
                if (i & (1 << k)) {
                    now += relation[j][k];
                }
            }
            s.insert(now);
        }
        if (s.size() == row && checkvalidation(ans, i)) {
            ans.push_back(i);
        }
    }
    answer = ans.size();
    return answer;
}
int main() {
    vector<vector<string>> strVector = {{"100", "ryan", "music", "2"},   {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"},
                                        {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"},  {"600", "apeach", "music", "2"}};
    cout << solution(strVector);
    return 0;
}