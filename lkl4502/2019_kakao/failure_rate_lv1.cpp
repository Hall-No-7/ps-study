#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int main() {
    fast_io;
    int N = 5;
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
    vector<pair<int, float>> tmp;

    sort(stages.begin(), stages.end());

    auto idx = find(stages.begin(), stages.end(), N + 1);
    int allClear = stages.end() - idx;
    stages.erase(idx, stages.end());

    auto start = stages.begin();
    for (int i = 1; i <= N; i++) {
        int cnt = count(start, stages.end(), i);
        if (cnt == 0) {
            tmp.push_back(make_pair(i, 0));
            continue;
        }
        float rate = cnt / float(stages.end() - start + allClear);
        tmp.push_back(make_pair(i, rate));
        start += cnt;
    }

    sort(tmp.begin(), tmp.end(),
         [](const pair<int, float> &stage1, const pair<int, float> &stage2) {
             if (stage1.second > stage2.second)
                 return true;
             if (stage1.second == stage2.second)
                 return stage1.first < stage2.first;
             return false;
         });

    vector<int> answer;
    for (int i = 0; i < tmp.size(); i++) {
        answer.push_back(tmp[i].first);
        cout << answer[i] << " ";
    }
    cout << endl;
}
