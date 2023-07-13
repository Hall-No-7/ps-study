#include <algorithm>
#include <bits/stdc++.h>
#include <list>
#include <string>
#include <vector>
#define ENDL "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cache;
    for (int i = 0; i < cities.size(); i++) {
        for (auto &ch : cities[i])
            ch = tolower(ch);

        auto it = find(cache.begin(), cache.end(), cities[i]);
        if (it == cache.end()) {
            // cache miss
            answer += 5;
            if (cache.size() == cacheSize && cacheSize > 0) {
                cache.pop_front();
                cache.push_back(cities[i]);
            } else if (cache.size() < cacheSize) {
                cache.push_back(cities[i]);
            }
        } else {
            // cache hit
            answer += 1;
            cache.erase(it);
            cache.push_back(cities[i]);
        }
    }
    return answer;
}