#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int main() {
    fast_io;
    vector<vector<string>> relation = {
        {"100", "ryan", "music", "2"},    {"200", "apeach", "math", "2"},
        {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"},
        {"500", "muzi", "music", "3"},    {"600", "apeach", "music", "2"}};

    int rowSize = relation.size(), colSize = relation[0].size();
    int len = 1;
    vector<int> nums;
    vector<string> answer;

    for (int i = 0; i < colSize; i++) // col 인덱스로 수열 만들기
        nums.push_back(i);

    while (len <= colSize) {
        vector<vector<int>> combiArray;
        vector<int> visit(colSize, 1);

        for (int i = 0; i < colSize - len; i++)
            visit[i] = 0; // 보조 수열 만들기

        do { // 조합 찾기
            vector<int> combi;
            for (int i = 0; i < nums.size(); i++)
                if (visit[i] != 0)
                    combi.push_back(nums[i]);
            combiArray.push_back(combi);
        } while (next_permutation(visit.begin(), visit.end()));

        for (int i = 0; i < combiArray.size(); i++) {
            vector<string> uniqueArray;
            for (int j = 0; j < rowSize;
                 j++) { // 구한 조합으로 relation 돌면서 문자열로 변환하여
                        // 벡터에 넣는다.
                string str;
                for (int k : combiArray[i])
                    str += relation[j][k];
                uniqueArray.push_back(str);
            }
            sort(uniqueArray.begin(),
                 uniqueArray.end()); // 문자열이 들어간 배열의 중복성 검사
            uniqueArray.erase(unique(uniqueArray.begin(), uniqueArray.end()),
                              uniqueArray.end());
            if (uniqueArray.size() == rowSize) { // 길이 같으면 후보키
                string combiStr;
                for (int j : combiArray[i])
                    combiStr += to_string(j);
                answer.push_back(combiStr);
            }
        }
        len++;
    }

    for (auto it = answer.begin(); it != answer.end(); it++) { // 최소성 검사
        // 14를 검사할때 014는 통과하지만 134는 통과하지 못함
        // answer.erase(remove_if(it + 1, answer.end(),
        //                        [it](const string &str) {
        //                            return str.find(*it) != string::npos;
        //                        }),
        //              answer.end());
        answer.erase(remove_if(it + 1, answer.end(),
                               [it](const string &str) {
                                   int cnt = 0;
                                   for (int i = 0; i < it->size(); i++) {
                                       if (str.find(it->at(i)) !=
                                           string::npos) {
                                           cnt++;
                                           continue;
                                       }
                                       break;
                                   }
                                   return cnt == it->size();
                                   //    return str.find(*it) != string::npos;
                               }),
                     answer.end());
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout << endl;
    cout << answer.size() << endl;
}