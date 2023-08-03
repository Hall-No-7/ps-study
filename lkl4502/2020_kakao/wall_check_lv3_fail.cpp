// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

// dist를 내림차순으로 정렬해서 하는 방식 실패

int main() {
    fast_io;
    int len = 200, answer = 0;
    vector<int> weak = {0, 10, 50, 80, 120, 160}, dist = {1, 10, 5, 40, 30};
    sort(dist.begin(), dist.end(), greater<int>());
    while (dist.size() != 0) { // 다 투입해도 못하면 -1을 리턴 해야하므로
        int workMan = dist[0];
        if (workMan >= len) {
            answer++;
            break;
        }
        int maxCnt = -1, start;
        for (int i = 0; i < weak.size(); i++) {
            // 가장 많이 움직일 수 잇는 일꾼이 가장 많이 점검하는 방식
            int cnt = upper_bound(weak.begin(), weak.end(),
                                  (workMan + weak[i]) % len) -
                      weak.begin() - i;
            if ((workMan + weak[i]) % len < weak[i])
                cnt += weak.size();
            start = (maxCnt < cnt) ? weak[i] : start;
            maxCnt = max(maxCnt, cnt);
        }
        dist.erase(dist.begin());
        auto it = find(weak.begin(), weak.end(), start);
        for (int i = 0; i < maxCnt; i++) {
            weak.erase(it);
            if (it == weak.end())
                it = weak.begin();
        }
        answer++;
        if (weak.size() == 0)
            break;
    }
    if (weak.size() != 0)
        answer = -1;
    cout << answer << endl;
}