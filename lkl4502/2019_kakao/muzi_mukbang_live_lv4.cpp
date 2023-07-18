#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int main() {
    fast_io;
    vector<int> food_times = {2, 2, 2, 2, 5, 1};
    vector<pair<int, int>> arrWithNum;
    long long k = 7;
    long long sum = 0ll;
    int answer = -1;

    for (int i = 0; i < food_times.size(); i++) {
        arrWithNum.push_back(make_pair(food_times[i], i + 1));
        sum += food_times[i];
    }

    sort(arrWithNum.begin(), arrWithNum.end());

    if (sum <= k)
        cout << answer << endl;
    // return answer;

    int len = food_times.size();
    int prevTime = 0;
    for (auto it = arrWithNum.begin(); it != arrWithNum.end(); it++, len--) {
        int minValue = it->first - prevTime;
        if (minValue == 0)
            continue; // 같은 시간 처리

        if (k < len * minValue) {
            int remain = k % len;
            sort(it, arrWithNum.end(),
                 [](const pair<int, int> &p1, const pair<int, int> &p2) {
                     return p1.second < p2.second;
                 });
            answer = (it + remain)->second;
            break;
        } else { // k > len * minValue 일경우
            k -= (long long)len * minValue;
            prevTime = it->first;
        }
    }

    // for (auto it : arrWithNum)
    //     cout << it.first << " " << it.second << endl;

    cout << answer << endl;
}