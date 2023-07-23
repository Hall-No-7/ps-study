#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt[501];
bool compare(pair<double, int> &a, pair<double, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> p;
    int person = stages.size();
    // 사람수 구하기
    for (int i = 0; i < person; i++) {
        cnt[stages[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 0) {
            p.push_back({0, i});
            continue;
        } else {
            double d = double(cnt[i]) / person;
            // cout << i << " " << cnt[i] << endl;
            p.push_back({d, i});
            person -= cnt[i];
        }
    }
    sort(p.begin(), p.end(), compare);
    for (int i = 0; i < p.size(); i++) {
        answer.push_back(p[i].second);
    }
    return answer;
}

int main() {
    vector<int> strVector = {2, 1, 2, 6, 2, 4, 3, 3};
    int N = 5;
    vector<int> answer;
    answer = solution(5, strVector);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    return 0;
}