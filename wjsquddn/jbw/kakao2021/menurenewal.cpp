#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (string& order : orders) {
        sort(order.begin(), order.end());
    }
    for (auto c : course) {
        map<string, int> m;
        for (string& order : orders) {
            if (order.length() > c) {
                vector<bool> comb(order.length() - c, false);
                for (int i = 0; i < c; i++) comb.push_back(true);
                do {
                    string temp = "";
                    for (int i = 0; i < order.length(); i++) {
                        if (comb[i]) temp += order[i];
                    }
                    m[temp]++;
                } while (next_permutation(comb.begin(), comb.end()));
            } else if (order.length() == c) {
                m[order]++;
            }
        }
        int max_val = max_element(m.begin(), m.end(), [](const pair<string, int>& a, const pair<string, int>& b) { return a.second < b.second; })->second;
        if (max_val < 2) continue;
        for (auto iter : m) {
            if (iter.second == max_val) {
                answer.push_back(iter.first);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    std::vector<std::string> strings = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    std::vector<int> numbers = {2, 3, 4};
    strings = solution(strings, numbers);
    // 벡터의 내용 출력
    for (const std::string& str : strings) {
        std::cout << str << std::endl;
    }
}