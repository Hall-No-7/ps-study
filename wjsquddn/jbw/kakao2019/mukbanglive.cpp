#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int n = food_times.size();
    long long sum;
    map<int, int> freq;
    set<int> time;
    for (int i = 0; i < n; i++) {
        freq[food_times[i]]++;
        time.insert(food_times[i]);
    }
    sum = 0;
    long long temp_n = n;
    long long prev = 0, now;
    for (set<int>::iterator it = time.begin(); it != time.end(); it++) {
        now = *it;
        long long temp = (now - prev) * temp_n;
        // 더하고
        //  k 보다 크면 전에 답이 있다는 뜻이므로 빠져 나오기
        if (sum + temp > k) break;
        sum += temp;
        temp_n -= freq[now];
        prev = now;
    }
    if (temp_n == 0) return -1;
    long long offset = k - sum;
    vector<pair<int, int>> notzero;
    for (int i = 0; i < n; ++i)
        if (food_times[i] >= now) notzero.push_back({food_times[i], i + 1});
    int index = offset % notzero.size();
    answer = notzero[index].second;
    return answer;
}
int main() {
    vector<int> food_times = {3, 1, 2};
    int k = 5;
    cout << solution(food_times, k);
    return 0;
}