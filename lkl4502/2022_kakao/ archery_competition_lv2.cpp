#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, vector<int> info) { // 10 ~ 0
    vector<int> answer;
    int maxScore = 0;
    reverse(info.begin(), info.end()); // 뒤집어야지 다음에 나오는 것들이 같은
                                       // 총점 이더라도 더 작은 점수대로 구성
    for (int i = 1; i <= 10; i++) {
        vector<bool> arr(11 - i, false);
        arr.insert(arr.end(), i, true);
        do {
            int ryanArrow = 0; // 해당 조합에서 라이언이 쏜 화살 개수
            for (int j = 0; j < arr.size(); j++)
                ryanArrow += arr[j] ? info[j] + 1 : 0;

            if (ryanArrow > n)
                continue;
            int ryanScore = 0, appeachScore = 0;

            for (int j = 0; j < arr.size(); j++) {
                ryanScore += (arr[j]) ? j : 0;
                appeachScore += (!arr[j] && info[j] != 0)
                                    ? j
                                    : 0; // 둘다 맞추지않은 점수대는 점수 x
            }
            int diff = ryanScore - appeachScore;
            if (diff < maxScore)
                continue;

            answer.clear();
            maxScore = diff;
            for (int j = 0; j < arr.size(); j++)
                answer.push_back(arr[j] ? info[j] + 1 : 0);
            answer[0] += n - ryanArrow;
        } while (next_permutation(arr.begin(), arr.end()));
    }
    if (answer.size() == 0 || maxScore == 0) { // maxScore == 0 비기는 경우 처리
        answer.clear();
        answer.push_back(-1);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}