#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11);
    vector<int> tmp(11);
    int maxDiff = 0;
    for (int subset = 1; subset < (1 << 10); subset++) {
        int ryan = 0;
        int apeach = 0;
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            if (subset & (1 << i)) {
                ryan += 10 - i;
                tmp[i] = info[i] + 1;
                cnt += tmp[i];
            } else {
                tmp[i] = 0;
                if (info[i] > 0) {
                    apeach += 10 - i;
                }
            }
        }
        if (cnt > n) continue;

        tmp[10] = n - cnt;
        if (ryan - apeach == maxDiff) {
            for (int i = 10; i >= 0; i--) {
                if (tmp[i] > answer[i]) {
                    maxDiff = ryan - apeach;
                    answer = tmp;
                    break;
                } else if (tmp[i] < answer[i]) {
                    break;
                }
            }
        } else if (ryan - apeach > maxDiff) {
            maxDiff = ryan - apeach;
            answer = tmp;
        }
    }
    if (maxDiff == 0) {
        return {-1};
    }
    return answer;
}
int main() {
    int n = 5;
    vector<int> info = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};

    vector<int> result = solution(n, info);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}