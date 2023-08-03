// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

/* dist로 만들 수 있는 모든 순열을 만들어서 전부 구한다.*/

int main() {
    fast_io;
    int len = 200, answer = -1;
    vector<int> weak = {0, 10, 50, 80, 120, 160}, dist = {1, 10, 5, 40, 30};
    sort(dist.begin(), dist.end());

    do {
        vector<int> tmp_weak = weak, tmp_dist = dist;
        int cnt = 0;
        while (tmp_dist.size() != 0) {
            int workMan = tmp_dist[0];
            if (workMan >= len) {
                cnt++;
                break;
            }
            int maxCnt = -1, start;
            for (int i = 0; i < tmp_weak.size(); i++) {
                int cnt = upper_bound(tmp_weak.begin(), tmp_weak.end(),
                                      (workMan + tmp_weak[i]) % len) -
                          tmp_weak.begin() - i;
                if ((workMan + tmp_weak[i]) % len < tmp_weak[i])
                    cnt += tmp_weak.size();
                start = (maxCnt < cnt) ? tmp_weak[i] : start;
                maxCnt = max(maxCnt, cnt);
            }
            tmp_dist.erase(tmp_dist.begin());
            auto it = find(tmp_weak.begin(), tmp_weak.end(), start);
            for (int i = 0; i < maxCnt; i++) {
                tmp_weak.erase(it);
                if (it == tmp_weak.end())
                    it = tmp_weak.begin();
            }
            cnt++;
            if (tmp_weak.size() == 0)
                break;
        }
        if (tmp_weak.size() != 0)
            cnt = -1;
        if (cnt == -1)
            continue;
        int tmp = (answer == -1) ? INT32_MAX : answer;
        answer = min(tmp, cnt);
    } while (next_permutation(dist.begin(), dist.end()));
    cout << answer << endl;
}